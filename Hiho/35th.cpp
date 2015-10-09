#include <stdio.h>
#include <iostream>

using namespace std;

const int N=1005;
const int M=5005;

struct Edge{
  int to,next;
}edge[2*M];
int head[N],cnt;
int choice[N],vis[N],color[N];
int n,m;

void addEdge(int f,int t){
  edge[cnt].to=t;
  edge[cnt].next=head[f];
  head[f]=cnt++;
}

void init(){
  for(int i=0;i<=n;i++)head[i]=-1,choice[i]=-1,color[i]=-1;
  cnt=0;
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
    if(choice[to]==-1||findPath(choice[to])){
      choice[to]=s;
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
    int a,b;
    cin>>a>>b;
    addEdge(a,b);
    addEdge(b,a);
  }
  for(int i=1;i<=n;i++)colorize(i,0);
  int ans=0;
  for(int i=1;i<=n;i++){
    if(!color[i]){
      for(int j=0;j<=n;j++)vis[j]=false;
      if(findPath(i))ans++;
    }
  }
  cout<<ans<<endl;
  cout<<n-ans<<endl;
  return 0;
}
