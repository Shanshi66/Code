#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;

int G[MAXN][MAXN];
int n,m;
bool visit[MAXN];

struct TopoNum{
	int v,topo;
}topoNum[MAXN];

void init(){
	for(int i=1;i<=n;i++){
		visit[i]=false;
		for(int j=1;j<=m;j++)G[i][j]=0;
	}
}

void topoOrder(int s,int &t){
	visit[s]=true;
	for(int i=1;i<=n;i++){
		if(G[s][i]&&!visit[i])topoOrder(i,t);
	}
	topoNum[s].v=s,topoNum[s].topo=t++;
}

bool cmp(TopoNum a,TopoNum b){
	if(a.topo>b.topo)return true;
	else return false;
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	init();
	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		G[u][v]=1;
	}
	int start=1;
	for(int i=1;i<=n;i++){
		if(!visit[i])topoOrder(i,start);
	}
	sort(topoNum+1,topoNum+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<topoNum[i].v<<" ";
	}
	cout<<endl;
	return 0;
}