#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20002;
const int MAXM = 100002;

struct Edge{
    int to, next;
} edges[MAXM];

int head[MAXN], order[MAXN], back[MAXN], food[MAXN], flag[MAXN];
int n, m, edge_cnt, comp_cnt, visit_order;
bool visit[MAXN];
bool inStack[MAXN];
stack<int> comps;
vector<int> food_sum;

Edge new_edges[MAXM];
int new_head[MAXN];
int new_edge_cnt;

void init(){
    for(int i = 0; i <= n; i++){
        head[i] = -1;
        visit[i] = false;
        new_head[i] = -1;
        inStack[i] = false;
    }
    visit_order = 0;
    edge_cnt = 0;
    comp_cnt = 0;
    new_edge_cnt = 0;
}

void add_edge(Edge e[], int h[], int from, int to, int &e_cnt){
    e[e_cnt].to = to;
    e[e_cnt].next = h[from];
    h[from] = e_cnt++;
}

void pop_stack(int t){
    int sum = 0;
    // cout << comp_cnt << endl;
    while(!comps.empty()){
        int top = comps.top();
        // cout << top << " ";
        sum += food[top];
        flag[top] = comp_cnt;
        comps.pop();
        inStack[top] = false;
        if(top == t) break;
    }
    // cout << endl;
    food_sum.push_back(sum);
    comp_cnt++;
}

void tarjan(int u){
    visit[u] = true;
    order[u] = back[u] = visit_order++;
    comps.push(u);
    inStack[u] = true;
    for(int i = head[u]; i != -1; i = edges[i].next){
        int v = edges[i].to;
        if(!visit[v]){
            tarjan(v);
            back[u] = min(back[u], back[v]);
        }else{
            if(inStack[v]){
                back[u] = min(back[u], order[v]);
            }
        }
    }
    if(back[u] == order[u]){
        pop_stack(u);
    }
    // cout << u << " " << order[u] << " " << back[u] << endl;
}

void dfs(int s){
    visit[s] = true;
    for(int i = head[s]; i != -1; i = edges[i].next){
        int t = edges[i].to;
        if(flag[s] != flag[t]) add_edge(new_edges, new_head, flag[s], flag[t], new_edge_cnt);
        if(!visit[t]) dfs(t);
    }
}

void build_new_graph(){
    for(int i = 0; i <= n; i++) visit[i] = false;
    dfs(1);
}

int dp(int s){
    // cout << s << endl;
    int _max = food_sum[s];
    for(int i = new_head[s]; i != -1; i = new_edges[i].next){
        _max = max(_max, food_sum[s] + dp(new_edges[i].to));
    }
    return _max;
}

int main(){
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    init();
    for(int i = 1; i <= n; i++){
        cin >> food[i];
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        add_edge(edges, head, u, v, edge_cnt);
    }
    tarjan(1);
    cout << comp_cnt << endl;
    build_new_graph();
    cout << dp(flag[1]) << endl;
    return 0;
}
