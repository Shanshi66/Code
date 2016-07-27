class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n][n];
        for(int j = 0; j < n; j++){
            // 须解决dp[k+1][j]，正序无法满足
            for(int i = j; i >= 0; i--){
                dp[i][j] = 0x7ffffff;
                if(i == j) dp[i][j] = 0;
                else if(i + 1 == j) dp[i][j] = i + 1;
                else {
                    //最小化最坏情况
                    for(int k = i + 1; k < j; k++){
                        dp[i][j] = min(dp[i][j], k + 1 + max(dp[i][k - 1], + dp[k + 1][j]));
                    }
                }
            }
        }
        return dp[0][n-1];
    } 
};