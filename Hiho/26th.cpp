#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int N = 1e3+1;
const int INF = 0x7fffffff;
int n,map[N][N];
int pre[N],p;
bool vis[N];

int main(){
  freopen("in.txt","r",stdin);
  cin>>n;
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>map[i][j];
  for(int i=1;i<=n;i++)pre[i]=INF,vis[i]=false;
  int temp=n-1;
  int ans=0;
  p=1;
  while(temp--){
    int tt=INF,tp;
    vis[p]=true;
    for(int i=1;i<=n;i++){
      if(vis[i])continue;
      if(pre[i]>map[i][p])pre[i]=map[i][p];
      if(i>1)if(pre[i]<tt)tp=i,tt=pre[i];
    }
    ans+=pre[tp];
    p=tp;
  }
  cout<<ans<<endl;
  return 0;
}
