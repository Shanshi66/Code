#include <stdio.h>

const int N=1e2+1;
const int M=1e3+1;
const int INF=0x3fffffff;
int dist[N][N];

int min(int x,int y){
  return x<y?x:y;
}

int main(){
  freopen("in.txt","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
      if(i==j)dist[i][j]=0;
      else dist[i][j]=INF;
  }
  int a,b,c;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&a,&b,&c);
    dist[a][b]=min(dist[a][b],c);
    dist[b][a]=min(dist[b][a],c);
  }
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  for(int i=1;i<=n;i++){
    printf("%d",dist[i][1]);
    for(int j=2;j<=n;j++){
      printf(" %d",dist[i][j]);
    }
    puts("");
  }
  return 0;
}
