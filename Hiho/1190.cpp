#include <bits/stdc++.h>

using namespace std;

const int N = 20002;
const int M = 100002;

struct Edge{
    int num;
    int to, next;
}edges[M * 2];
int head[N], order[N], back[N], parent[N], mark[M];
int cnt, n, m, comp_cnt;
bool visit[N];
stack<int> components;
set< pair<int, int> > edge_flag;

void init(){
    for(int i = 0; i <= n; i++){
        head[i] = -1;
        visit[i] = false;
        parent[i] = -1;
    }
    cnt = 0;
    comp_cnt = 0;
}

void add_edge(int from, int to, int num){
    edges[cnt].num = num;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

void popStackUntil(int end){
    int _min = M;
    vector<int> comp;
    while(!components.empty()){
        int top = components.top();
        _min = min(_min, edges[top].num);
        comp.push_back(edges[top].num);
        components.pop();
        if(top == end) break;
    }
    for(vector<int>::iterator iter = comp.begin(); iter != comp.end(); iter++){
        mark[*iter] = _min;
    }
}

void tarjan(int u){
    static int counter = 0;
    order[u] = back[u] = counter++;
    visit[u] = true;
    int children = 0;
    for(int i = head[u]; i != -1; i = edges[i].next){
        int v = edges[i].to;
        if(edge_flag.find(make_pair(v, u)) == edge_flag.end() &&
           edge_flag.find(make_pair(u, v)) == edge_flag.end()){
            components.push(i);
            edge_flag.insert(make_pair(u, v));
            edge_flag.insert(make_pair(v, u));
        }
        if(!visit[v]){
            parent[v] = u;
            children++;
            tarjan(v);
            back[u] = min(back[v], back[u]);
            if(parent[u] == -1 && (children > 1 || back[u] == order[u])){
                comp_cnt++;
                popStackUntil(i);
            }
            if(parent[u] != -1 && back[v] >= order[u]){
                // cout << u << endl;
                comp_cnt++;
                popStackUntil(i);
            }
        }else{
            if(v != parent[u]){
                back[u] = min(order[v], back[u]);
            }
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        add_edge(u, v, i + 1);
        add_edge(v, u, i + 1);
    }
    tarjan(1);
    cout << comp_cnt << endl;
    for(int i = 1; i <= m; i++){
        cout << mark[i] << " ";
    }
    cout << endl;
    return 0;
}