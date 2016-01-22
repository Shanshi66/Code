#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100;
const int maxm = 100;

int n,m;
struct Edge{
    int u,v,l;
};

bool cmp(const Edge &a,const Edge &b){
    return a.l<b.l;
}

int find(int f[],int x){
    if(x==f[x])return f[x];
    else return f[x]=find(f,f[x]);
}

void merge(int f[],int a,int b){
    f[find(f,a)]=find(f,b);
}

int kruscal(Edge edge[],int f[],int n,int m){
    for(int i=1;i<=n;i++)f[i]=i;
    sort(edge,edge+m,cmp);
    int weight=0;
    for(int cnt=1,i=0;cnt<n&&i<m;i++){
        if(find(f,edge[i].u)!=find(f,edge[i].v)){
            weight+=edge[i].l;
            merge(f,edge[i].u,edge[i].v);
            cnt++;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    cin>>n>>m;
    Edge *edge = new Edge[m];
    int *f = new int[n];
    for(int i=0;i<m;i++){
        cin>>edge[i].u>>edge[i].v>>edge[i].l;
    }
    cout<<kruscal(edge,f,n,m)<<endl;
    delete [] edge;
    delete [] f;
    return 0;
}
