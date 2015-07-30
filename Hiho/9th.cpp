#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN=1002;
const int MAXM=5;
const int  MOD=1000000007;
//连在一起
int up[7]={3,6,12,15,24,27,30};

int dp[2][1<<MAXM];

bool can(int a){
  int count=0,flag=1;
  for(int i=0;i<MAXM;i++){
    if(a&flag)count++;
    else{
      if(count&1)return false;
    }
    flag=flag<<1;
  }
  return true;
}

void init(){
  memset(dp,0,sizeof(dp));
  for(int i=0;i<(1<<MAXM);i++){
    //第一行检查
    if(can(i))dp[0][i]=1;
  }
}

int getDp(int m,bool flag,int j){
  //当前行为0，上一行一定为1,
  //当前行为1，如果没有相邻1，上一行一定为0，上一行为0表示有一块板子跨到当前行
  //如果有相邻1，考虑up数组的7种情况
  int sum=0;
  sum+=dp[flag][(m-1)^j];
  for(int i=0;i<7;i++){
    if((up[i]&j)==up[i]){
      //判断是属于哪一种情况，((m-1)^j)|up[i]得出相邻1是在当前行横着放上一行的情况
      sum=(sum+dp[flag][((m-1)^j)|up[i]])%MOD;
    }
  }
  return sum%MOD;
}

int main(){
  freopen("in.txt","r",stdin);
  init();
  int n,m;
  cin>>n>>m;
  if((n*m)&1){
    cout<<0<<endl;
    return 0;
  }
  if(n<m)swap(n,m);
  m=1<<m;
  bool flag=false;
  for(int i=0;i<n;i++,flag=!flag){
    for(int j=0;j<m;j++){
      dp[!flag][j]=getDp(m,flag,j);
    }
  }
  cout<<dp[!flag][m-1]<<endl;
  return 0;
}
