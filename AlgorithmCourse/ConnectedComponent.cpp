#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;

int G[MAXN][MAXN];
bool visit[MAXN];
int label[MAXN];
int n,m,cnt;

void init(){
	cnt=0;
	for(int i=1;i<=n;i++){
		visit[i]=false;
		label[i]=0;
		for(int j=1;j<=i;j++)G[i][j]=0;
	}
}

void dfs(int s){
	label[s]=cnt;
	visit[s]=true;
	for(int i=1;i<=n;i++){
		if(!visit[i]&&G[i][s])dfs(i);
	}
}

void connectedComponent(){
	for(int i=1;i<=n;i++){
		if(!visit[i]){
			cnt++;
			dfs(i);
		}
	}
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
	}
	connectedComponent();
	for(int i=1;i<=n;i++){
		cout<<label[i]<<" ";
	}
	cout<<endl;
	return 0;
}