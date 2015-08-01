#include <stdio.h>

const int maxn =1e4+1;
int n,q;
int weight[maxn];

int main(){
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&weight[i]);
  scanf("%d",&q);
  while(q--){
    int op,a,b,ans=1e4+4;
    scanf("%d%d%d",&op,&a,&b);
    if(op)weight[a-1]=b;
    else{
      for(int i=a-1;i<b;i++)ans=ans<weight[i]?ans:weight[i];
      printf("%d\n",ans);
    }
  }
}
