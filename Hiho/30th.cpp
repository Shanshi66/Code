#include <stdio.h>
#include <iostream>

using namespace std;

const int maxn = 1e5+5;

int n,mines[maxn];
bool flag[2][maxn];

void init(){
  flag[0][0]=false,flag[1][0]=true;
}

bool scan(int t){
  for(int i=0;i<n;i++){
    int cnt;
    if(i==0)cnt=mines[i]-flag[t][i];
    else cnt=mines[i]-flag[t][i]-flag[t][i-1];
    if(cnt<0||cnt>1)return false;
    if(i==n-1&&cnt!=0)return false;
    flag[t][i+1]=cnt;
  }
  return true;
}

int main(){
  freopen("in.txt","r",stdin);
  int tcase;
  init();
  cin>>tcase;
  while(tcase--){
    cin>>n;
    int t;
    bool flag1=false,flag2=false;
    for(int i=0;i<n;i++)cin>>mines[i];
    if(mines[0]==0)flag1=scan(0);
    else if(mines[0]==2)flag2=scan(1);
    else flag1=scan(0),flag2=scan(1);
    int cnt1=0,cnt2=0;
    if(flag1&flag2)t=2;
    else if(flag1)t=0;
    else t=1;
    if(t==0||t==1){
      for(int i=0;i<n;i++){
        if(flag[t][i])cnt1++;
        else cnt2++;
      }
      printf("%d",cnt1);
      for(int i=0;i<n;i++){
        if(flag[t][i])printf(" %d",i+1);
      }
      printf("\n%d",cnt2);
      for(int i=0;i<n;i++){
        if(!flag[t][i])printf(" %d",i+1);
      }
      cout<<endl;
    }
    else{
      for(int i=0;i<n;i++){
        if(flag[0][i]&flag[1][i])cnt1++;
        if(!(flag[0][i]|flag[1][i]))cnt2++;
      }
      printf("%d",cnt1);
      for(int i=0;i<n;i++){
        if(flag[0][i]&flag[1][i])printf(" %d",i+1);
      }
      printf("\n%d",cnt2);
      for(int i=0;i<n;i++){
        if(!(flag[0][i]|flag[1][i]))printf(" %d",i+1);
      }
      cout<<endl;
    }
  }
}
