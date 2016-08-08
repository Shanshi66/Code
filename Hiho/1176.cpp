#include <bits/stdc++.h>

using namespace std;

const int MAX_VERTEX = 10001;
int degree[MAX_VERTEX];
int n, m;

void init(){
    for(int i = 0; i <= n; i++){
        degree[i] = 0;
    }
}

int main(){
    cin >> n >> m;
    //init();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    int odd_node_count = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] & 1) odd_node_count++;
    }
    if(odd_node_count == 2 || odd_node_count == 0) cout << "Full" << endl;
    else cout << "Part" << endl;
    return 0;
}