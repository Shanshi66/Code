#include <bits/stdc++.h>

using namespace std;

const int N = 20002;
const int M = 100002;

struct Edge{
    int to, next;
};
Edge edges[M * 2];
int cnt = 0, n, m, order;
int head[N], parent[N], visit_order[N], low[N];
bool visit[N];
// vector<int> cut_points;
set<int> cut_points;
vector< pair<int, int> > cut_edges;

void add_edge(int from, int to){
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt++;
}

void init(){
    cnt = 0;
    order = 0;
    for(int i = 0; i <= n; i++){
        head[i] = -1;
        visit[i] = false;
        parent[i] = -1;
    }
    cut_points.clear();
    cut_edges.clear();
}

void dfs(int u){
    visit[u] = true;
    visit_order[u] = low[u] = order++;
    int children = 0;
    for(int i = head[u]; i != -1; i = edges[i].next){
        int v = edges[i].to;
        if(!visit[v]){
            children++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            //root
            if(parent[u] == -1 && children > 1){
                // cut_points.push_back(u);
                cut_points.insert(u);
            }
            //not root
            if(parent[u] != -1 && visit_order[u] <= low[v]){
                // cut_points.push_back(u);
                cut_points.insert(u);
            }
            //brige
            if(low[v] > visit_order[u]){
                cut_edges.push_back(make_pair(min(u, v), max(u, v)));
            }
        }
        else{
            if(v != parent[u]){
                low[u] = min(low[u], visit_order[v]);
            }
        }
    }
    // cout << u << " " << visit_order[u] << " " << low[u] << endl;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
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
    dfs(1);
    if(cut_points.empty()){
        cout << "Null" << endl;
    }else{
        // sort(cut_points.begin(), cut_points.end());
        for(auto i: cut_points){
            cout << i << " ";
        }
        cout << endl;
    }
    if(!cut_edges.empty()){
        sort(cut_edges.begin(), cut_edges.end(), cmp);
        for(auto i: cut_edges){
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}
