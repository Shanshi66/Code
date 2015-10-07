#include <stdio.h>
#include <iostream>

using namespace std;

const int N=10005;
const int M=40005;
int n,m;

struct Edge{
  int to,next;
}edge[2*M];
int head[N],cnt;
int color[N];

void init(){
  cnt=0;
  //color初始-1,黑0，白1
  for(int i=0;i<=n;i++)head[i]=-1,color[i]=-1;
}

void addEdge(int from,int to){
  edge[cnt].to=to;
  edge[cnt].next=head[from];
  head[from]=cnt++;
}

bool dfs(int p,int c){
  if(color[p]>=0)return true;
  color[p]=c;
  for(int i=head[p];i!=-1;i=edge[i].next){
    if(color[edge[i].to]>=0){
      if(color[edge[i].to]==c)return false;
    }
    else{
      if(!dfs(edge[i].to,c^1))return false;
    }
  }
  return true;
}

int main(){
  freopen("in.txt","r",stdin);
  int task;
  cin>>task;
  while(task--){
    cin>>n>>m;
    init();
    int from,to;
    for(int i=0;i<m;i++){
      cin>>from>>to;
      addEdge(from,to);
      addEdge(to,from);
    }
    bool flag=true;
    //可能不联通，好心机
    for(int i=1;i<=n;i++){
      if(!dfs(i,0))flag=false;
    }
    if(flag)cout<<"Correct"<<endl;
    else cout<<"Wrong"<<endl;
  }
  return 0;
}
