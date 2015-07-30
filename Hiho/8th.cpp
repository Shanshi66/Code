#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXM=10;
const int MAXN=1000;

int dp[1<<MAXM][2];
int w[MAXN+10];
int qsum[1<<MAXM];
int n,m,q;

void init(){
  memset(dp,0,sizeof(dp));
  memset(qsum,0,sizeof(qsum));
  int t=1<<MAXM;
  for(int i=0;i<t;i++){
    int temp=i;
    while(temp){
      temp=temp&(temp-1);
      qsum[i]++;
    }
  }
}

int main(){
  //freopen("in.txt","r",stdin);
  init();
  scanf("%d%d%d",&n,&m,&q);
  for(int i=0;i<n;i++)scanf("%d",&w[i]);
  bool flag=0;
  for(int i=0;i<n;i++,flag=!flag){
    for(int j=0;j<(1<<m);j++){
      if(qsum[j]<q)dp[j][!flag]=max(dp[(j>>1)+(1<<(m-1))][flag],dp[j>>1][flag])+(j&1)*w[i];
      if(qsum[j]==q){
        if(j&1)dp[j][!flag]=max(dp[(j>>1)+(1<<(m-1))][flag]+w[i],dp[j>>1][flag]+w[i]);
        else dp[j][!flag]=dp[j>>1][flag];
      }
    }
  }
  int ans=0;
  for(int i=0;i<(1<<m);i++)ans=max(ans,dp[i][flag]);
  printf("%d\n",ans);
}
