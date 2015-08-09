#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

const int maxn = 1e5;
const int maxm = 1e6;
const int INF=0x3fffffff;
struct Edge{
  int to,next,v;
}edge[maxm];
int head[maxn];
int dist[maxn];
bool flag[maxn];
int n,m,s,t,cnt;

void init(){
  memset(head,-1,sizeof(head));
  cnt=0;
}

void add(int from,int to,int val){
  edge[cnt].to=to;
  edge[cnt].next=head[from];
  edge[cnt].v=val;
  head[from]=cnt++;
}

void spfa(){
  queue<int> que;
  for(int i=0;i<=n;i++)flag[i]=false,dist[i]=INF;
  dist[s]=0;
  que.push(s);
  flag[s]=true;
  while(!que.empty()){
    int t=que.front();
    for(int i=head[t];i!=-1;i=edge[i].next){
      int temp=dist[t]+edge[i].v;
      if(dist[edge[i].to]>temp){
        dist[edge[i].to]=temp;
        if(!flag[edge[i].to])que.push(edge[i].to),flag[edge[i].to]=true;
      }
    }
    que.pop();
    flag[t]=false;
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
