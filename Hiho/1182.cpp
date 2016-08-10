#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

const int MAXN = 15;
const int MAX_VERTEX = 1 << (MAXN - 1);
const int MAX_EDGES = 1 << MAXN;
int n, vertex_num;

struct Edge{
    int to, next;
    void assign(int to, int next){
        this->to = to;
        this->next = next;
    }
};
Edge edges[MAX_EDGES];
int head[MAX_VERTEX];
bool flag[MAX_EDGES];
int cnt = 0;
stack<int> path;

void add_edge(int from, int to){
    edges[cnt].assign(to, head[from]);
    head[from] = cnt++;
}

void build_graph(){
    for(int i = 0; i < vertex_num; i++){
        add_edge(i, (i << 1) & (vertex_num - 1));
        add_edge(i, (i << 1) & (vertex_num - 1) | 1);
    }
}

void init(){
    vertex_num = 1 << (n - 1);
    for(int i = 0; i < vertex_num; i++){
        head[i] = -1;
    }
    for(int i = 0; i < MAX_EDGES; i++){
        flag[i] = true;
    }
    cnt = 0;
}

void dfs(int s){
    for(int e = head[s]; e != -1; e = edges[e].next){
        if(flag[e]){
            flag[e] = false;
            dfs(edges[e].to);
        }
    }
    path.push(s);
}


int main()
{
    cin >> n;
    init();
    build_graph();
    dfs(0);
    string ans;
    if(!path.empty()) path.pop();
    while(!path.empty()){
        if(path.top() & 1) ans += '1';
        else ans += '0';
        path.pop();
    }
    cout << ans << endl;
    return 0;
}

