#include <stdio.h>
#include <iostream>

using namespace std;

const int N=10000;
const int M=100000;

struct Edge{
  int to,v,next;
}edge[M];
int head[N];
int n,m,k,t,cnt;

void init(){
  for(int i=0;i<=N;i++)head[i]=-1;
  cnt=0;
}

void add(int from,int to,int v){
  edge[cnt].to=to;
  edge[cnt].v=v;
  edge[cnt].next=head[from];
  head[from]=cnt++;
}

int main(){
  cin>>n>>m>>k>>t;
  init();
  int u,v,w;
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    add(u,v,w);
    add(v,u,w);
  }

  return 0;
}
