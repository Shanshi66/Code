class Solution {
public:
    int minPathSum(vector< vector<int> > &grid){
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector< vector<int> > pathSum;
        for(int i = 0; i < m; i++){
            vector<int> row(n, 0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) {
                    row[j] = grid[i][j];
                } else if (i == 0) {
                    row[j] = row[j - 1] + grid[i][j];
                } else if(j == 0) {
                    row[j] = pathSum[i - 1][j] + grid[i][j];
                }
                else {
                    row[j] = min(pathSum[i - 1][j], row[j - 1]) + grid[i][j];
                }
            }
            pathSum.push_back(row);
        }
        return pathSum[m - 1][n - 1];
    }
};