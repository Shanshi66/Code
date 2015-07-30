#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN=1e5+5;

struct Edge{
  int next,to;
}edge[2*MAXN];//无向图，双向边

int head[2*MAXN];
int n,cnt=0;
int maxlen=-1,node;

void add(int s,int e){
  edge[cnt].to=e;
  edge[cnt].next=head[s];
  head[s]=cnt++;
}

void init(){
  memset(head,-1,sizeof(head));
}

void dfs(int now,int pre,int d){
  if(d>maxlen){
    maxlen=d;
    node=now;
  }
  if(now==0)return;
  for(int i=head[now];i!=-1;i=edge[i].next){
    if(edge[i].to!=pre){
      dfs(edge[i].to,now,d+1);
    }
  }
}

int main(){
  freopen("in.txt","r",stdin);
  init();
  cin>>n;
  for(int i=0;i<n-1;i++){
    int s,e;
    cin>>s>>e;
    add(s,e),add(e,s);
  }
  dfs(1,-1,0);
  maxlen=-1;
  dfs(node,-1,0);
  cout<<maxlen<<endl;
  return 0;
}
