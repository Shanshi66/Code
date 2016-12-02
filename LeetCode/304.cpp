class NumMatrix {
public:
    vector< vector<int> > matrix_sum;
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            matrix_sum.push_back(vector<int>(m, 0));
            for(int j = 0; j < m; j++) {
                matrix_sum[i][j] = matrix[i][j];
                if(i == 0 && j == 0) {
                    continue;
                } else if(i == 0) {
                    matrix_sum[i][j] += matrix_sum[i][j - 1];
                } else if(j == 0) {
                    matrix_sum[i][j] += matrix_sum[i - 1][j];
                } else {
                    matrix_sum[i][j] += matrix_sum[i - 1][j] + 
                                        matrix_sum[i][j - 1] - 
                                        matrix_sum[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = matrix_sum[row2][col2];
        if(col1 >= 1) ans -= matrix_sum[row2][col1 - 1];
        if(row1 >= 1) ans -= matrix_sum[row1 - 1][col2];
        if(col1 >= 1 && row1 >= 1) ans += matrix_sum[row1 - 1][col1 - 1];
        return ans;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);