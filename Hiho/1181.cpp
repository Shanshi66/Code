#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

const int MAX_VERTEX = 1001;
const int MAX_EDGE = 5001;
int n, m;
int graph[MAX_VERTEX][MAX_VERTEX];
int degree[MAX_VERTEX];
queue<int> path;


void init(){
    for(int i = 1; i <= n; i++){
        degree[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = 0;
        }
    }
    while(!path.empty())path.pop();
}

void dfs(int u){
    for(int i = 1; i <= n; i++){
        if(graph[u][i] > 0){
            graph[u][i]--;
            graph[i][u]--;
            dfs(i);
        }
    }
    path.push(u);
}


int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v]++; 
        graph[v][u]++;
        degree[u]++;
        degree[v]++;
    }
    int start = 1;
    for(int i = 1; i <= n ; i++){
        if(degree[i] & 1){
            start = i;
            break;
        }
    }
    dfs(start);
    while(!path.empty()){
        cout << path.front() << " ";
        path.pop();
    }
    cout << endl;
    return 0;
}


