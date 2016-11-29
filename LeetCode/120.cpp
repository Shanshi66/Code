class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector< vector<int> > dp(2, vector<int>(rows, 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < rows; i++){
            for(int j = 0; j <= i; j++){
                if(j == 0) {
                    dp[i & 1][j] = dp[(i - 1) & 1][j] + triangle[i][j];
                } else if(j == i){
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1] + triangle[i][j];
                } else {
                    dp[i & 1][j] = min(dp[(i - 1) & 1][j], dp[(i - 1) & 1][j - 1]) + triangle[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < rows; i++){
            ans = min(ans, dp[(rows - 1) & 1][i]);
        }
        return ans;
    }
};