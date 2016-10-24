class Solution{
public:
    int longestIncreasingPath(vector< vector<int> >& matrix){
        int n = matrix.size(), m;
        if(n == 0) return 0;
        m = matrix[0].size();
        vector< vector<int> > longestPath;
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < m; j++){
                row.push_back(-1);
            }
            longestPath.push_back(row);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(matrix, longestPath, i, j, n, m, 1));
            }
        }
        return ans;
    }
    int dfs(vector< vector<int> >& matrix, 
            vector< vector<int> >& longestPath, 
            int x, int y, int n, int m, int len){
        if(longestPath[x][y] != -1) return len + longestPath[x][y];
        int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
        longestPath[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            if(inSide(xx, yy, n, m) && matrix[x][y] < matrix[xx][yy]){
                longestPath[x][y] = max(longestPath[x][y], dfs(matrix, longestPath, xx, yy, n, m, len + 1));
            }
        }
        return len + longestPath[x][y];
    }
    bool inSide(int x, int y, int n, int m){
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        return true;
    }
};
