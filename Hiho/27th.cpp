#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1e5+1;
const int maxm = 1e6+1;
int n,m;
int f[maxn];
struct Edge{
  int u,v,l;
}edge[maxm];

bool cmp(const Edge &a,const Edge &b){
  return a.l<b.l;
}

int find(int x){
  if(x==f[x])return f[x];
  else return f[x]=find(f[x]);
}

void merge(int a,int b){
  f[find(a)]=find(b);
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>m;
  for(int i=0;i<m;i++)cin>>edge[i].u>>edge[i].v>>edge[i].l;
  for(int i=1;i<=n;i++)f[i]=i;
  sort(edge,edge+m,cmp);
  int cnt=0,i=0,ans=0;
  while(cnt<n-1&&i<m){
    if(find(edge[i].u)!=find(edge[i].v)){
      ans+=edge[i].l;
      merge(edge[i].u,edge[i].v);
      cnt++;
    }
    i++;
  }
  cout<<ans<<endl;
  return 0;
}
