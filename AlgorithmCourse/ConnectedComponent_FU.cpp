#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;

int n,m;
struct Edge{
    int u,v;
}edge[MAXM];
int f[MAXN];

int find(int x){
    if(x==f[x])return f[x];
    else return f[x]=find(f[x]);
}

void merge(int a,int b){
    f[find(a)]=find(b);
}

int connectedComponent(){
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        if(find(edge[i].u)!=find(edge[i].v))merge(edge[i].u,edge[i].v);
    }
}

int main(){
    freopen("in.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=m;i++)cin>>edge[i].u>>edge[i].v;
    connectedComponent();
	for(int i=1;i<=n;i++)cout<<find(i)<<endl;
}
