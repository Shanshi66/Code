#include <bits/stdc++.h>

using namespace std;

const int N = 1002, M = 100;

int n, m;
int satisfaction[N];

struct Edge{
    int to, next;
};
Edge edges[N * 2];
int head[N], cnt;
int degree[N];
int dp[N][M][2][2];

void init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(dp, 0, sizeof(dp));
    memset(degree, 0, sizeof(degree));
}

void addEdge(int from, int to){
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

void dfs(int root, int father){
    bool isLeaf = true;
    int child_cnt = 0;
    for(int i = head[root]; i != -1; i = edges[i].next){
        if(edges[i].to == father) continue;
        isLeaf = false;
        child_cnt++;
        dfs(edges[i].to, root);
    }
    if(child_cnt == 1){
        int child = edges[head[root]].to;
        for(int i = 0; i <= m; i++){
            dp[root][i][0][0] = max(dp[child][i][0][0], dp[root][i][0][0]);
            // dp[root][i][0][0] = max(dp[child][i][0][1], dp[root][i][0][0]);
            dp[root][i][0][1] = max(dp[child][i][1][1] + satisfaction[root], dp[root][i][0][1]);
            dp[root][i + 1][1][1] = max(dp[child][i][0][0] + satisfaction[root] + satisfaction[child], 
                                        dp[root][i + 1][1][1]);
            dp[root][i + 1][1][1] = max(dp[child][i][0][1] + satisfaction[root], dp[root][i + 1][1][1]);
            dp[root][i + 1][1][1] = max(dp[child][i][1][1] + satisfaction[root], dp[root][i + 1][1][1]);
        }
    }
    if(child_cnt == 2){
        int child1 = edges[head[root]].to;
        int child2 = edges[edges[head[root]].next].to;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= m; j++){
                if(i + j > m) continue;
                dp[root][i + j][0][0] = max(dp[child1][i][0][0] + dp[child2][j][0][0],
                                            dp[root][i + j][0][0]);
                dp[root][i + j][0][0] = max(dp[child1][i][0][0] + dp[child2][j][0][1],
                                            dp[root][i + j][0][0]);
                dp[root][i + j][0][0] = max(dp[child1][i][0][1] + dp[child2][j][0][0],
                                            dp[root][i + j][0][0]);
                dp[root][i + j][0][0] = max(dp[child1][i][0][1] + dp[child2][j][0][1],
                                            dp[root][i + j][0][0]);
                
                dp[root][i + j][0][1] = max(dp[child1][i][1][1] + dp[child2][j][0][0] + satisfaction[root], 
                                            dp[root][i + j][0][1]);
                dp[root][i + j][0][1] = max(dp[child1][i][1][1] + dp[child2][j][0][1] + satisfaction[root], 
                                            dp[root][i + j][0][1]);
                dp[root][i + j][0][1] = max(dp[child1][i][0][0] + dp[child2][j][1][1] + satisfaction[root], 
                                            dp[root][i + j][0][1]);
                dp[root][i + j][0][1] = max(dp[child1][i][0][1] + dp[child2][j][1][1] + satisfaction[root], 
                                            dp[root][i + j][0][1]);
                dp[root][i + j][0][1] = max(dp[child1][i][1][1] + dp[child2][j][1][1] + satisfaction[root], 
                                            dp[root][i + j][0][1]);

                dp[root][i + j + 1][1][1] = max(dp[child1][i][0][0] + dp[child2][j][0][0] + 
                                                satisfaction[child1] + satisfaction[child2] + satisfaction[root],
                                                dp[root][i + j + 1][1][1]);
                dp[root][i + j + 1][1][1] = max(dp[child1][i][0][1] + dp[child2][j][0][0] + 
                                                satisfaction[root] + satisfaction[child2],
                                                dp[root][i + j + 1][1][1]);
                dp[root][i + j + 1][1][1] = max(dp[child1][i][0][0] + dp[child2][j][0][1] + 
                                                satisfaction[child1] + satisfaction[root],
                                                dp[root][i + j + 1][1][1]);
                dp[root][i + j + 1][1][1] = max(dp[child1][i][0][1] + dp[child2][j][0][1] + 
                                                satisfaction[root],
                                                dp[root][i + j + 1][1][1]); 
                
                dp[root][i + j + 1][1][1] = max(dp[child1][i][1][1] + dp[child2][j][0][0]+
                                                satisfaction[child2] + satisfaction[root],
                                                dp[root][i + j + 1][1][1]);
                dp[root][i + j + 1][1][1] = max(dp[child1][i][1][1] + dp[child2][j][0][1] + 
                                                satisfaction[root],
                                                dp[root][i + j + 1][1][1]);
                dp[root][i + j + 1][1][1] = max(dp[child1][i][1][1] + dp[child2][j][1][1] + 
                                                satisfaction[root],
                                                dp[root][i + j + 1][1][1]);
            }
        }
    }
    if(isLeaf){
        for(int i = 1; i <= m; i++){
            dp[root][i][1][1] = satisfaction[root];
        }
        return;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    init();
    for(int i = 1; i <= n; i++){
        cin >> satisfaction[i];
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
        degree[u]++, degree[v]++;
    }
    int root;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 1 || degree[i] == 2){
            dfs(root = i, -1);
            break;
        }
    }
    int ans = -1;
    for(int i = 0; i <= m; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                ans = max(ans, dp[root][i][j][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}