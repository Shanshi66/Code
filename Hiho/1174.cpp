#include <bits/stdc++.h>

using namespace std;

const int MAX_VERTEX = 100000;
const int MAX_EDGE = 500000;

struct Edge{
    int to, next_edge;
};
Edge edges[MAX_EDGE];
int income_degree[MAX_VERTEX + 1];
int last_edge[MAX_VERTEX + 1];
int cnt = 0;
int case_number, n, m;

void init(){
    for(int i = 1; i <= n; i++){
        last_edge[i] = 0;
        income_degree[i] = 0;
    }
    cnt = 0;
}

void addEdge(int from, int to){
    cnt++;
    edges[cnt].to = to;
    edges[cnt].next_edge = last_edge[from];
    last_edge[from] = cnt;
}

int main()
{
    cin >> case_number;
    while(case_number--){
        cin >> n >> m;
        init();
        for(int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            income_degree[b]++;
            addEdge(a, b);
        }
        queue<int> zero_income_nodes;
        for(int i = 1; i <= n; i++){
            if(income_degree[i] == 0) zero_income_nodes.push(i);
        }
        int count = n;
        while(!zero_income_nodes.empty()){
            int first = zero_income_nodes.front();
            zero_income_nodes.pop();
            count--;
            for(int edge = last_edge[first]; edge; edge = edges[edge].next_edge){
                if((--income_degree[edges[edge].to]) == 0){
                    zero_income_nodes.push(edges[edge].to);
                }
            }
        }
        if(count > 0) cout << "Wrong" << endl;
        else cout << "Correct" << endl;
        
    }
    return 0;
}

