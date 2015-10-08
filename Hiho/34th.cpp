#include <stdio.h>
#include <iostream>

using namespace std;

const int N=1004;
const int M=5005;

struct Edge{
  int to,next;
  bool v;
}edge[2*M];

int chosen[N];
int head[N],color[N],vis[N];
int cnt,n,m;

void init(){
  for(int i=0;i<=n;i++)head[i]=-1,color[i]=-1,chosen[i]=-1;
  cnt=0;
}

void addEdge(int from,int to){
  edge[cnt].to=to;
  edge[cnt].v=false;
  edge[cnt].next=head[from];
  head[from]=cnt++;
}

void colorize(int s,int c){
  if(color[s]!=-1)return;
  color[s]=c;
  for(int i=head[s];i!=-1;i=edge[i].next)colorize(edge[i].to,c^1);
}

bool findPath(int s){
  for(int i=head[s];i!=-1;i=edge[i].next){
    int to=edge[i].to;
    if(vis[to])continue;
    vis[to]=true;
    if(chosen[to]==-1||findPath(chosen[to])){
      chosen[to]=s;
      return true;
    }
  }
  return false;
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>m;
  init();
  for(int i=0;i<m;i++){
    int from,to;
    cin>>from>>to;
    addEdge(from,to);
    addEdge(to,from);
  }
  for(int i=1;i<=n;i++)colorize(i,0);
  int cnt=0;
  for(int i=1;i<=n;i++){
    if(!color[i]){
      for(int j=1;j<=n;j++)vis[j]=false;
      if(findPath(i))cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
