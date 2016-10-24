class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)return 0;
        int m = grid[0].size();
        vector< vector<bool> > vis;
        for(int i = 0; i < n; i++){
            vector<bool> row;
            for(int j = 0; j < m; j++){
                row.push_back(false);
            }
            vis.push_back(row);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, vis, i, j, n, m);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector< vector<char> >& grid, vector< vector<bool> >& vis, int x, int y, int n, int m){
        if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == '0' || vis[x][y]) return;
        vis[x][y] = true;
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i < 4; i++){
            int xx = x + dir[i][0], yy = y + dir[i][1];
            dfs(grid, vis, xx, yy, n, m);
        }
    }
};