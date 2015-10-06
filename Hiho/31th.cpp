#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

typedef pair<int,int> pos;

const int MAXN=2e2+5;
int mines[MAXN][MAXN];
int n,m;
int dir[8][2]={{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};

void init(){
  for(int i=0;i<n+3;i++)
    for(int j=0;j<m+3;j++)
      mines[i][j]=0;
}

int main(){
  freopen("in.txt","r",stdin);
  int tcase;
  cin>>tcase;
  while(tcase--){
    init();
    cin>>n>>m;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++)cin>>mines[i][j];
    }
    //rule1
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(mines[i][j]==0){
          for(int k=0;k<8;k++){
            int x=i+dir[k][0],y=j+dir[k][1];
            //no mine -2
            if(mines[x][y]==-1)mines[x][y]=-2;
          }
        }
      }
    }
    //rule2
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(mines[i][j]>0){
          int cnt=0;
          for(int k=0;k<8;k++){
            int x=i+dir[k][0],y=j+dir[k][1];
            //if(mines[x][y]==-1||mines[x][y]==-3)cnt++;
            //小ho很傻
            if(mines[x][y]<0)cnt++;
          }
          if(cnt==mines[i][j]){
            for(int k=0;k<8;k++){
              int x=i+dir[k][0],y=j+dir[k][1];
              if(mines[x][y]<0)mines[x][y]=-3;
            }
          }
        }
      }
    }
    //rule3
    set<pos> a[2];
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(mines[i][j]<0)continue;
        a[0].clear();
        for(int k=0;k<8;k++){
          int x=i+dir[k][0],y=j+dir[k][1];
          if(mines[x][y]<0)a[0].insert(make_pair(x,y));
        }
        for(int s=-2;s<=2;s++){
          for(int t=-2;t<=2;t++){
            if(i+s>n||i+s<1)continue;
            if(j+t>m||j+t<1)continue;
            if(mines[i+s][j+t]<0)continue;
            if(!s&&!t)continue;
            a[1].clear();
            for(int k=0;k<8;k++){
              int x=i+s+dir[k][0],y=j+t+dir[k][1];
              if(mines[x][y]<0)a[1].insert(make_pair(x,y));
            }
            int bi,sm;
            if(a[0].size()>a[1].size())bi=0,sm=1;
            else bi=1,sm=0;
            int p[2][2]={{i,j},{i+s,j+t}};
            set<pos>::iterator it;
            bool isChild=true;
            for(it=a[sm].begin();it!=a[sm].end();it++){
              if(a[bi].find(*it)==a[bi].end()){
                isChild=false;
                break;
              }
            }
            if(isChild){
              int temp1=mines[p[bi][0]][p[bi][1]]-mines[p[sm][0]][p[sm][1]];
              int temp2=a[bi].size()-a[sm].size();
              if(temp1==temp2){
                set<pos>::iterator it;
                for(it=a[bi].begin();it!=a[bi].end();it++){
                  if(a[sm].find(*it)==a[sm].end()){
                    mines[it->first][it->second]=-3;
                  }
                }
              }
            }
          }
        }
      }
    }
    int cnt1=0,cnt2=0;//无，有
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(mines[i][j]==-2)cnt1++;
        if(mines[i][j]==-3)cnt2++;
      }
    }
    cout<<cnt2<<" "<<cnt1<<endl;
  }
  return 0;
}
