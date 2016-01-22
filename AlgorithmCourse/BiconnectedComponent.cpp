#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;

int n,m,cnt;
int G[MAXN][MAXN];
int label[MAXN][MAXN];
int discover[MAXN];
int back[MAXN];
int color[MAXN];

struct Edge{
	int from,to;
};

void init(){
	cnt=0;
	for(int i=1;i<=n;i++){
		color[i]=0;
		for(int j=1;j<=n;j++)G[i][j]=0,label[i][j]=0;
	}
}

int findBCC(stack<Edge> &edgeStack,int &t,int s,int p){
	color[s]=1;
	discover[s]=t,back[s]=t++;
	for(int i=1;i<=n;i++){
		if(!G[s][i]||i==p)continue;
		Edge e;e.from=s,e.to=i;
		if(!color[i]){
			edgeStack.push(e);
			int wback=findBCC(edgeStack,t,i,s);
			if(wback>=discover[s]){
				cnt++;
				while(1){
					Edge temp=edgeStack.top();
					label[temp.from][temp.to]=label[temp.to][temp.from]=cnt;
					edgeStack.pop();
					if(temp.from==e.from&&temp.to==e.to)break;
				}
			}
			else back[s]=min(back[s],wback);
		}
		if(color[i]==1){
			edgeStack.push(e);
			back[s]=min(back[s],discover[i]);
		}
	}
	t++;
	color[s]=2;
	return back[s];
}

void biConnectedComponent(){
	stack<Edge> edgeStack;
	int start=1;
	for(int i=1;i<=n;i++){
		if(!color[i])findBCC(edgeStack,start,i,-1);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	cin>>n>>m;
	init();
	for(int i=1,u,v;i<=m;i++){
		cin>>u>>v;
		G[u][v]=G[v][u]=1;
	}
	biConnectedComponent();
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<label[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}