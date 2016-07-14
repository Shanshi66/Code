class Solution {
public:
    int maxSumSubmatrix(vector< vector<int> >& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int cum_matrix[row][col];
        //预处理，对每行累积求和
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(j == 0)cum_matrix[i][j] = matrix[i][j];
                else cum_matrix[i][j] = cum_matrix[i][j - 1] + matrix[i][j];
            }
        }
        int max_sum = -0x7fffffff;
        set<int> cum_sum;
        //扫描线，固定两列，变成一个在以为数组中寻找最大不超过k的子序列
        for(int i = 0; i < col; i++){
            for(int j = i; j < col; j++){
                int f, tmp = 0;
                cum_sum.clear();
                // 二分
                for(int s = 0; s < row; s++){
                    cum_sum.insert(tmp);
                    if(i == 0) f = cum_matrix[s][j];
                    else f = cum_matrix[s][j] - cum_matrix[s][i - 1];
                    tmp += f;
                    set<int>::iterator iter = cum_sum.upper_bound(tmp-k-1);
                    if(iter != cum_sum.end()){
                        max_sum = max(max_sum, tmp - *iter);
                    }
                }
            }
        }
        return max_sum;
    }
};

