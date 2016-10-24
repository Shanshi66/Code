#include <bits/stdc++.h>

using namespace std;

const int N = 100, M = 100;
int n, m;
int grid[N][M];
int maxSum[N][M];

int dfs(int x, int y){
    if(x == 0 && y == 0) return maxSum[x][y] = grid[x][y];
    if(maxSum[x][y] != -1) return maxSum[x][y];
    int _max = -1;
    if(x > 0){
        maxSum[x][y] = max(_max, dfs(x - 1, y) + grid[x][y]);
    }
    if(y > 0){
        maxSum[x][y] = max(_max, dfs(x, y - 1) + grid[x][y]);
    }
    return maxSum[x][y];
}

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            maxSum[i][j] = -1;
        }
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    init();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }
    int ans = dfs(n - 1, m - 1);
    cout << ans << endl;
    return 0;
}