class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, 0);
        for(int i = 0; i <= n; i++){
            if(i == 0 || i == 1) dp[i] = 1;
            else {
                for(int j = 0; j < n; j++){
                    dp[i] += dp[j] * dp[i-j-1];
                }
            }
        }
        return dp[n];
    }
};