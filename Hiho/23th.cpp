#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>

using namespace std;

const int N=1e3+1;
const int M=1e4+1;
const int INF=0x3fffffff;

struct Edge{
  int to,l,next;
}edge[M];
int head[N];
int cnt;
int n,m,s,t;
int dist[N];
bool vis[N];

void add(int from,int to,int len){
  edge[cnt].to=to;
  edge[cnt].l=len;
  edge[cnt].next=head[from];
  head[from]=cnt++;
}

void init(){
  memset(head,-1,sizeof(head));
  cnt=0;
  memset(vis,false,sizeof(vis));
}

void spfa(){
  for(int i=1;i<=n;i++)dist[i]=INF;
  dist[s]=0;
  queue<int> q;
  q.push(s);
  vis[s]=true;
  while(!q.empty()){
    int t=q.front();
    for(int i=head[t];i!=-1;i=edge[i].next){
      int temp=dist[t]+edge[i].l;
      if(dist[edge[i].to]>temp){
        dist[edge[i].to]=temp;
        if(!vis[edge[i].to]){
          q.push(edge[i].to);
          vis[edge[i].to]=true;
        }
      }
    }
    q.pop();
    vis[t]=false;
  }
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>m>>s>>t;
  init();
  int a,b,c;
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    add(a,b,c);
    add(b,a,c);
  }
  spfa();
  cout<<dist[t]<<endl;
  return 0;
}
