class Solution {
public:
    int coinChange(vector<int> &coins, int amount){
        int coins_num = coins.size();
        const int INF = INT_MAX;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins_num; j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INF){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        if(dp[amount] == INF) return -1;
        return dp[amount];
    }
};