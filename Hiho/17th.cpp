#include <stdio.h>
#include <math.h>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;

const int maxn=1e5+1;
int n,count;
map<string,int> names;
string toName[maxn];
int pre_cal[maxn][20];
int who[maxn][20];

struct Seq{
  int depth,num;
}seq[maxn*2];
int toSeq[maxn*2];
int seqcnt;

struct Edge{
  int to,next;
}edge[maxn];
int head[maxn];
int cnt;

int last_appear[maxn];

void add(int from,int to){
  edge[cnt].to=to;
  edge[cnt].next=head[from];
  head[from]=cnt++;
}

void init(){
  memset(head,-1,sizeof(head));
  //  memset(who,-1,sizeof(who));
  cnt=0;
  count=0;
  seqcnt=0;
}

void dfs(int root,int d){
  seq[seqcnt].depth=d;
  seq[seqcnt].num=root;
  toSeq[root]=seqcnt++;
  for(int i=head[root];i!=-1;i=edge[i].next){
    dfs(edge[i].to,d+1);
    seq[seqcnt].depth=d;
    seq[seqcnt].num=root;
    toSeq[root]=seqcnt++;
  }
}

void preprocess(){
  for(int i=seqcnt-1;i>=0;i--){
    pre_cal[i][0]=seq[i].depth;
    who[i][0]=seq[i].num;
    int b=log(seqcnt-i+1)/log(2);
    for(int j=1;j<=b;j++){
      int temp=i+(1<<(j-1));
      if(temp<seqcnt){
        if(pre_cal[i][j-1]<pre_cal[temp][j-1])pre_cal[i][j]=pre_cal[i][j-1],who[i][j]=who[i][j-1];
        else pre_cal[i][j]=pre_cal[temp][j-1],who[i][j]=who[temp][j-1];
      }
      else{
        pre_cal[i][j]=pre_cal[i][j-1];
        who[i][j]=who[i][j-1];
      }
    }
  }
}

int main(){
  freopen("in.txt","r",stdin);
  init();
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    string f,s;
    cin>>f>>s;
    if(names.find(f)==names.end())names[f]=count,toName[count++]=f;
    if(names.find(s)==names.end())names[s]=count,toName[count++]=s;
    add(names[f],names[s]);
  }
  dfs(0,1);
  //  for(int i=0;i<seqcnt;i++)cout<<toName[seq[i].num]<<" ";
  //  cout<<endl;
  preprocess();
  cin>>n;
  for(int i=0;i<n;i++){
    string a,b;
    cin>>a>>b;
    int ans;
    int from=toSeq[names[a]],to=toSeq[names[b]];
    if(from>to)swap(from,to);
    int T=log(to-from+1)/log(2);
    int temp=to-(1<<T)+1;//+1
    if(temp<from)cout<<toName[who[from][T]]<<endl;
    else{
      if(pre_cal[from][T]<pre_cal[temp][T])cout<<toName[who[from][T]]<<endl;
      else cout<<toName[who[temp][T]]<<endl;
    }
  }
  return 0;
}
