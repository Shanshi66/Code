#include <stdio.h>
#include <iostream>

using namespace std;

const int N=12;

int mines[N][N];
int yesno[N][N];
int n,m;
int dir[8][2];

void init_dir(){
  int cnt=0;
  for(int i=-1;i<=1;i++){
    for(int j=-1;j<=1;j++){
      if(!j&&!i)continue;
      dir[cnt][0]=i;
      dir[cnt++][1]=j;
    }
  }
}

void init(){
  for(int i=0;i<n+2;i++){
    for(int j=0;j<m+2;j++){
      yesno[i][j]=-1;
      mines[i][j]=0;
    }
  }
}

void forward(int &x,int &y){
  if(y+1<=m)y=y+1;
  else x=x+1,y=1;
}

void backward(int &x,int &y){
  if(y-1>=1)y=y-1;
  else x=x-1,y=m;
}

bool judge(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(mines[i][j]>=0){
        int cnt=0;
        for(int k=0;k<8;k++){
          int x=i+dir[k][0],y=j+dir[k][1];
          if(mines[x][y]==-2)cnt++;
        }
        if(cnt!=mines[i][j])return false;
      }
    }
  }
  return true;
}

void update(){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(mines[i][j]==-2){
        if(yesno[i][j]==-1)yesno[i][j]=1;
        if(yesno[i][j]==0)yesno[i][j]=2;
      }
      if(mines[i][j]==-3){
        if(yesno[i][j]==-1)yesno[i][j]=0;
        if(yesno[i][j]==1)yesno[i][j]=2;
      }
    }
  }
}

void dfs(int x,int y){
  if(x>n){
    if(judge()){
      update();
    }
    return;
  }
  if(mines[x][y]!=-1){
    forward(x,y);
    dfs(x,y);
  }
  else{
    for(int i=-2;i>=-3;i--){
      int temp=mines[x][y];
      mines[x][y]=i;
      forward(x,y);
      dfs(x,y);
      backward(x,y);
      mines[x][y]=temp;
    }
  }
}

int main(){
  freopen("in.txt","r",stdin);
  init_dir();
  int task;
  cin>>task;
  while(task--){
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        cin>>mines[i][j];
      }
    }
    dfs(1,1);
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(yesno[i][j]==0)cnt1++;
        if(yesno[i][j]==1)cnt2++;
      }
    }
    cout<<cnt2<<" "<<cnt1<<endl;
  }
  return 0;
}
