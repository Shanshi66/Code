class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        vector< vector<int> > dp;
        dp.push_back(vector<int>(n, 1));
        dp.push_back(vector<int>(n, 0));
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == 0) dp[i & 1][j] = dp[(i - 1) & 1][j];
                else dp[i & 1][j] = dp[(i - 1) & 1][j] + dp[i & 1][j - 1];
            }
        }
        return dp[(m - 1) & 1][n - 1];
    }
};