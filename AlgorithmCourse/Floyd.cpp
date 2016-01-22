#include <cstdio>
#include <iostream>
#include <math.h>

using namespace std;

const int INF =0x3fffffff;
int n,m;
int weight[100][100];

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)weight[i][j]=0;
			else weight[i][j]=INF;
		}
	}
}

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				weight[i][j]=min(weight[i][j],weight[i][k]+weight[k][j]);
			}
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	init();
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		weight[u][v]=weight[v][u]=w;
	}
	floyd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<weight[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}