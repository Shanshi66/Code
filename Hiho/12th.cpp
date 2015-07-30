#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN=1e2+5;

struct Edge{
  int to,next;
}edge[2*MAXN];
int head[2*MAXN];
int n,m,cnt;
int f[MAXN][MAXN];
int v[MAXN];

void init(){
  cnt=0;
  memset(head,-1,sizeof(head));
  memset(f,0,sizeof(f));
}

void add(int s,int e){
  edge[cnt].to=e;
  edge[cnt].next=head[s];
  head[s]=cnt++;
}

int dfs(int root){
  for(int i=head[root];i!=-1;i=edge[i].next){
    dfs(edge[i].to);
    for(int j=m;j>1;j--){
      for(int k=1;k<j;k++){
        f[root][j]=max(f[root][j],f[root][j-k]+f[edge[i].to][k]);
      }
    }
  }
}

int main(){
  freopen("in.txt","r",stdin);
  init();
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>f[i][1];
  for(int i=0;i<n-1;i++){
    int s,e;
    cin>>s>>e;
    add(s,e);
  }
  dfs(1);
  cout<<f[1][m]<<endl;
  return 0;
}
