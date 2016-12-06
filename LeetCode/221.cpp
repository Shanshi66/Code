/*
枚举每个位置，二分查找
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        if(m == 0) return 0;
        vector< vector<int> > sum(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(matrix[i][j] == 0) continue;
                int l = 0, r = min(n - i, m - j);
                while(l <= r) {
                    int m = (l + r) / 2;
                    int sum_should_be = (m + 1) * (m + 1);
                    int sum_in_fact = sum[i+m][j+m] - sum[i+m][j-1] - sum[i-1][j+m] + sum[i-1][j-1];
                    if(sum_in_fact != sum_should_be) r = m - 1;
                    else l = m + 1;
                }
                ans = max(ans, l - 1);
            }
        }
        ans += 1;
        return ans;
    }
};

/*
discuss solution O(mn)
b[i][j] represent the largest edge len of square ended in i, j
*/
public int maximalSquare(char[][] a) {
    if(a.length == 0) return 0;
    int m = a.length, n = a[0].length, result = 0;
    int[][] b = new int[m+1][n+1];
    for (int i = 1 ; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(a[i-1][j-1] == '1') {
                b[i][j] = Math.min(Math.min(b[i][j-1] , b[i-1][j-1]), b[i-1][j]) + 1;
                result = Math.max(b[i][j], result); // update result
            }
        }
    }
    return result*result;
}