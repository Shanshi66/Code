#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

const int MAX_VERTEX = 100000 + 1;
const int MAX_EDGE = 500000 + 1;
const int MOD = 142857;

struct Edge{
    int to, next;
};

Edge edges[MAX_EDGE];
int last_edge[MAX_VERTEX], cnt;
int virus[MAX_VERTEX], income_degree[MAX_VERTEX];
int n, m, k, ans;

void add_edge(int from, int to){
    cnt++;
    edges[cnt].to = to;
    edges[cnt].next = last_edge[from];
    last_edge[from] = cnt;
}

void init(){
    for(int i = 0; i <= n; i++){
		last_edge[i] = 0;
		virus[i] = 0;
		income_degree[i] = 0;
	}
	cnt = ans = 0;
}

inline void scan_d(int &ret) {  
    char c; ret=0;  
    while((c=getchar())<'0'||c>'9');  
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();  
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scan_d(n);
    scan_d(m);
    scan_d(k);
    // cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int hack_point;
        cin >> hack_point;
        virus[hack_point] = 1;
    }
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
		income_degree[v]++;
        add_edge(u, v);
    }
	queue<int> zero_income_nodes;
	for(int i = 0; i <= n; i++){
		if(income_degree[i] == 0) zero_income_nodes.push(i);
	}
    while(!zero_income_nodes.empty()){
        int node = zero_income_nodes.front();
        zero_income_nodes.pop();
        for(int edge = last_edge[node]; edge; edge = edges[edge].next){
			virus[edges[edge].to] = (virus[edges[edge].to] + virus[node]) % MOD;
			if((--income_degree[edges[edge].to]) == 0){
				zero_income_nodes.push(edges[edge].to);
			}
		}
    }
	for(int i = 1; i <= n; i++) ans = (ans + virus[i]) % MOD;
    cout << ans << endl;
    return 0;
}


