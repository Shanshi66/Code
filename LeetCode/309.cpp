class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector< vector<int> > dp(n, vector<int>(3, 0));
        // 0: buy, 1: sell, 2: cooldown
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                dp[i][0] = max(dp[i][0], dp[j][2]);
                dp[i][1] = max(dp[i][1], dp[j][0] + prices[i] - prices[j]);
                dp[i][2] = max(dp[i][2], dp[j][1]);
            }
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};


/*
From discuss

dp[i][0]表示前i天中，以buy结尾的最大收益
dp[i][1]表示前i天中，以sell结尾的最大收益
dp[i][2]表示前i天中，以cooldown结尾的最大收益

由状态转移公式可以看出，dp[i][2] >= dp[i][0], 所以不会出现buy, cooldown, buy的情况

以前想状态都是：
dp[i]: sequence end with operation, and this operation happens at i
这里:
any sequence end with sell/buy/rest before i
原因在于:
Because this problem says "as many transactions as you want", unlike only one or two transactions.

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector< vector<int> > dp(n + 1, vector<int>(3, 0));
        // 0: buy, 1: sell, 2: cooldown
        dp[0][0] = 0 - prices[0]; dp[0][1] = 0; dp[0][2] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
            dp[i][2] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};