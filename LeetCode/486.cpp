/*
dp[i][j]表示i-j这个区间，先手能获得的最大收益
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        for(int i = 0; i < n; i++) {
            if(i == 0) sum[i] = nums[i];
            else sum[i] = sum[i - 1] + nums[i];
        }
        vector< vector<int> > dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j + i < n; j++) {
                if(i == 0) dp[j][j + i] = nums[j];
                else if(j == 0) {
                    dp[j][j + i] = max(nums[j + i] + sum[j + i - 1] - dp[j][j + i - 1], 
                                       sum[j + i] - dp[j + 1][j + i]);
                } else {
                    dp[j][j + i] = max(nums[j + i] + sum[j + i - 1] - sum[j - 1] - dp[j][j + i - 1],
                                       nums[j] + sum[j + i] - sum[j] - dp[j + 1][j + i]);
                }
                //cout << j << " " << j + i << " " << dp[j][j + i] << endl;
            }
        }
        if(dp[0][n - 1] >= sum[n - 1] - dp[0][n - 1]) return true;
        else return false;
    }
};