#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int N=1e6+5;
int n,k;
int num[N];

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>k;
  for(int i=0;i<n;i++)cin>>num[i];
  if(k>n||k<0)cout<<"-1"<<endl;
  else{
    sort(num,num+n);
    cout<<num[k-1]<<endl;
  }
  return 0;
}
