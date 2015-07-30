#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <set>

using namespace std;

map<string,string> zupu;
//标记一条路径，并将路径上所有点放入vis中
set<string> vis;

void slove(string name1,string name2){
  vis.clear();
  vis.insert(name1);
  string temp=name1;
  while(zupu.find(temp)!=zupu.end()){
    vis.insert(zupu[temp]);
    temp=zupu[temp];
  }
  temp=name2;
  if(vis.find(temp)!=vis.end()){
    cout<<temp<<endl;
    return;
  }
  while(zupu.find(temp)!=zupu.end()){
    if(vis.find(zupu[temp])!=vis.end()){
      cout<<zupu[temp]<<endl;
      return;
    }
    temp=zupu[temp];
  }
  cout<<-1<<endl;
}

int main(){
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    string father,son;
    cin>>father>>son;
    zupu[son]=father;
  }
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    string name1,name2;
    cin>>name1>>name2;
    slove(name1,name2);
  }
  return 0;
}
