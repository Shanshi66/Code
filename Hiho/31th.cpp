#include <stdio.h>
#include <iostream>

using namespace std;

const int MAXN=2e2+5;
int mines[MAXN][MAXN];
int n,m;

int main(){
  int tcase;
  cin>>tcase;
  while(tcase--){
    cin>>n>>m;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)cin>>mines[i][j];
    }
  }
  return 0;
}
