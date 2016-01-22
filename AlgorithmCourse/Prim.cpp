#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;
const int INF =0x3fffffff;

int G[MAXN][MAXN];
bool visit[MAXN];
int father[MAXN];
int fringe[MAXN];
int n,m;

void init(int n){
	for(int i=1;i<=n;i++){
		visit[i]=false,father[i]=-1,fringe[i]=INF;
		for(int j=1;j<=n;j++){
			if(i==j)G[i][j]=0;
			else G[i][j]=INF;
		}
	}
}

int prim(int s){
	int minV=s,times=n,total_weight=0;
	fringe[s]=0;
	while(times--){
		visit[minV]=true;
		total_weight+=fringe[minV];
		for(int i=1;i<=n;i++){
			if(visit[i])continue;
			if(fringe[i]>G[minV][i])fringe[i]=G[minV][i],father[i]=minV;
		}
		minV=-1;
		for(int i=1;i<=n;i++){
			if(visit[i])continue;
			if(minV==-1||fringe[i]<fringe[minV])minV=i;
		}
	}
	return total_weight;
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	init(n);
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=w;
	}
	cout<<prim(1)<<endl;
	for(int i=1;i<=n;i++)cout<<i<<" "<<father[i]<<endl;
	return 0;
}