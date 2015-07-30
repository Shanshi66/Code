#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<string,string> hb;

string find_represent(string a){
  if(a==hb[a])return hb[a];
  else return hb[a]=find_represent(hb[a]);
}

int main(){
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  while(n--){
    int op;
    string a,b;
    cin>>op>>a>>b;
    if(hb.find(b)==hb.end())hb[b]=b;
    if(hb.find(a)==hb.end())hb[a]=a;
    if(op){
      if(find_represent(a)==find_represent(b))cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
    else{
      hb[find_represent(a)]=find_represent(b);
    }
  }
  return 0;
}
