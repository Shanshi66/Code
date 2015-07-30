#include <stdio.h>
#include <string.h>
#include <cmath>

const int maxn=1e6+1;
const int maxm=20;
int n,q,l,r;
int weight[maxn];
int pre_cal[maxn][maxm];

int min(int x,int y){
  return x>y?y:x;
}

void preprocess(){
  for(int i=n-1;i>=0;i--){
    pre_cal[i][0]=weight[i];
    int b=log(n-i+1)/log(2);
    for(int j=1;j<=b;j++){
      int temp=i+(1<<(j-1));
      if(temp<n)
        pre_cal[i][j]=min(pre_cal[i][j-1],pre_cal[i+(1<<(j-1))][j-1]);
      else
        pre_cal[i][j]=pre_cal[i][j-1];
    }
  }
}

int main(){
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&weight[i]);
  preprocess();
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    scanf("%d%d",&l,&r);
    l--,r--;
    int t=log(r-l+1)/log(2);
    printf("%d\n",min(pre_cal[l][t],pre_cal[r-(1<<t)+1][t]));
  }
  return 0;
}
