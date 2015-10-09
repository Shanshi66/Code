#include <stdio.h>
#include <iostream>

using namespace std;

const int N=1e6+5;
int num,n,k;

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>k;
  int t=0;
  bool flag=false;
  for(int i=0;i<n;i++){
    cin>>num;
    if(num<k)t++;
    if(num==k)flag=true;
  }
  if(flag)cout<<t+1<<endl;
  else cout<<-1<<endl;
  return 0;
}
