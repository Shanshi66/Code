#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int N=1e5+1;
map<string,int> names;
struct Edge{
  int to,next;
}edge[N];
int first[N];
int cnt;

string toName[N];

int query[N][2];
int ans[N];
int color[N+1];
vector<int> iquery[N];
int uset[N];
int count;
int n,m;

void init(){
  count=0;
  cnt=0;
  memset(first,-1,sizeof(first));
  memset(color,0,sizeof(color));
  memset(uset,-1,sizeof(uset));
}

void add(int from,int to){
  edge[cnt].to=to;
  edge[cnt].next=first[from];
  first[from]=cnt++;
}

int find(int x){
  if(x==uset[x])return x;
  else return uset[x]=find(uset[x]);
}

void dfs(int root){
  uset[root]=root;
  color[root]=1;
  for(vector<int>::iterator iter=iquery[root].begin();
      iter!=iquery[root].end();iter++){
    int q=query[*iter][0]==root?query[*iter][1]:query[*iter][0];
    if(color[q]==1)ans[*iter]=q;
    if(color[q]==2)ans[*iter]=find(q);
  }
  for(int i=first[root];i!=-1;i=edge[i].next){
    dfs(edge[i].to);
    color[edge[i].to]=2;
    uset[find(edge[i].to)]=find(root);
  }
}


int main(){
  freopen("in.txt","r",stdin);
  init();
  cin>>n;
  for(int i=0;i<n;i++){
    string a,b;
    cin>>a>>b;
    if(names.find(a)==names.end())names[a]=count,toName[count++]=a;
    if(names.find(b)==names.end())names[b]=count,toName[count++]=b;
    add(names[a],names[b]);
  }
  cin>>m;
  for(int i=0;i<m;i++){
    string a,b;
    cin>>a>>b;
    int na=names[a],nb=names[b];
    query[i][0]=na;
    query[i][1]=nb;
    iquery[na].push_back(i);
    iquery[nb].push_back(i);
  }
  dfs(0);
  for(int i=0;i<m;i++){
    cout<<toName[ans[i]]<<endl;
  }
  return 0;
}
