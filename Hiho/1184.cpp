#include<bits/stdc++.h>

using namespace std;

const int MAXN = 20002;
const int MAXM = 100002;

struct Edge{
    int to, next;
};
Edge edges[MAXM * 2];
int cnt, n, m, order_cnt;
int head[MAXN], order[MAXN], back[MAXN], parent[MAXN];
int ans[MAXN];
bool visit[MAXN];
stack<int> components;
int comp_cnt;

void init(){
    cnt = 0;
    comp_cnt = 0;
    order_cnt = 0;
    for(int i = 0; i <= n; i++){
        head[i] = -1;
        visit[i] = false;
        parent[i] = -1;
    }
}

void add_edge(int from, int to){
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

void pop_stack(int til){
    vector<int> comp;
    int _min = n + 1;
    while(!components.empty()){
        int t = components.top();
        comp.push_back(t);
        _min = min(_min, t);
        components.pop();
        if(t == til) break;
    }
    for(auto node: comp){
        ans[node] = _min;
    }
}

void tarjan(int u){
    visit[u] = true;
    order[u] = back[u] = order_cnt++;
    components.push(u);
    for(int i = head[u]; i != -1; i = edges[i].next){
        int v = edges[i].to;
        if(!visit[v]){
            parent[v] = u;
            tarjan(v);
            back[u] = min(back[u], back[v]);
            //if(order[u] < back[v]){
            //    comp_cnt++;
            //    pop_stack(v);
            //}
        }else{
            if(v != parent[u]){
                back[u] = min(back[u], order[v]);
            }
        }
    }
    if(order[u] == back[u]){
        comp_cnt++;
        pop_stack(u);
    }
    // cout << u << " " << order[u] << " " << back[u] << endl;
}

int main(){
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    tarjan(1);
    //if(!components.empty()){
    //    comp_cnt++;
    //    pop_stack(1);
    //}
    cout << comp_cnt << endl;
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
