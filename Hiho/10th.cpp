#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int findChar(string str,int b,int e,char c){
  for(int i=b;i<=e;i++){
    if(str[i]==c)return i;
  }
  return -1;
}

string work(string pre,int bpre,int epre,string mid,int bmid,int emid){
  if(bpre==epre){
    //到达叶子节点
    string temp;
    return temp+pre[bpre];
  }
  //空子树
  if(bpre>epre||bmid>emid)return "";
  char root=pre[bpre];
  int index=findChar(mid,bmid,emid,root);
  int lenleft=index-bmid;
  string left=work(pre,bpre+1,bpre+lenleft,mid,bmid,index-1);
  string right=work(pre,bpre+lenleft+1,epre,mid,index+1,emid);
  return left+right+root;
}

int main(){
  freopen("in.txt","r",stdin);
  string pre,mid;
  cin>>pre>>mid;
  cout<<work(pre,0,pre.length()-1,mid,0,mid.length()-1)<<endl;
  return 0;
}
