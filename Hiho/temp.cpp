#include <cstdio>
#define M ((1<<m)-1)

int k[]={3,6,12,24,15,27,30},f[1001][32]={1},n,m,i,j,s,o=1e9+7;

int main(){
  freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&m);
  for(i=0;i<n;++i){
    for(s=M;s;--s)for(j=0;j<7;++j)if((s&k[j])==k[j])f[i][s]=(f[i][s]+f[i][s&~k[j]])%o;
    for(s=0;s<=M;++s)f[i+1][M&~s]=(f[i+1][M&~s]+f[i][s])%o;
  }
  printf("%d\n",f[n-1][M]);
}
