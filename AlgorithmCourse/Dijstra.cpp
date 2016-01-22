#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;
const int INF =0x3fffffff;

int G[MAXN][MAXN];
bool visit[MAXN];
int father[MAXN];
int dist[MAXN];
int n,m;

void init(int n){
	for(int i=1;i<=n;i++){
		visit[i]=false,father[i]=-1,dist[i]=INF;
		for(int j=1;j<=n;j++){
			if(i==j)G[i][j]=0;
			else G[i][j]=INF;
		}
	}
}

void Dijkstra(int s){
	int minV=s,times=n;
	dist[s]=0;
	while(times--){
		visit[minV]=true;
		for(int i=1;i<=n;i++){
			if(visit[i])continue;
			if(dist[i]>G[minV][i]+dist[minV])dist[i]=G[minV][i]+dist[minV],father[i]=minV;
		}
		minV=-1;
		for(int i=1;i<=n;i++){
			if(visit[i])continue;
			if(minV==-1||dist[i]<dist[minV])minV=i;
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	init(n);
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		G[u][v]=G[v][u]=w;
	}
	Dijkstra(1);
	for(int i=1;i<=n;i++)cout<<dist[i]<<endl;
	for(int i=1;i<=n;i++)cout<<i<<" "<<father[i]<<endl;
	return 0;
}