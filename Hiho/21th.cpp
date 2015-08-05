#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define LC(x) (x<<1)
#define RC(x) ((x<<1)+1)
using namespace std;

const int maxn=1e5+1;
struct Interval{
  int l,r,p;
  int lazy;
}seq[maxn*8];
int poster[2*maxn];
int disp[2*maxn];
int n,L,m;
int cnt;
int ans[2*maxn];

int bisearch(int x){
  int l=0,r=m-1,mid;
  while(l<=r){
    mid=(r-l)/2+l;
    if(x<disp[mid])r=mid;
    else if(x==disp[mid])return mid;
    else l=mid+1;
  }
}

int disperse(int a[],int len){
  sort(a,a+len);
  //去重
  int i,j;
  for(i=0,j=1;j<len;){
    if(a[j]==a[i])j++;
    else a[i+1]=a[j++],i++;
  }
  return i+1;
}

void build(int root,int le,int ri){
  seq[root].l=le,seq[root].r=ri;
  seq[root].lazy=-1;
  seq[root].p=-1;
  if(le+1==ri)return;
  int mid=(ri-le)/2+le;
  build(LC(root),le,mid);
  build(RC(root),mid,ri);
}

void modify(int root,int le,int ri,int w){
  if(seq[root].l==le&&seq[root].r==ri){
    seq[root].lazy=w;
    seq[root].p=w;
  }
  else{
    if(seq[root].lazy!=-1){
      seq[LC(root)].lazy=seq[RC(root)].lazy=seq[root].lazy;
      seq[LC(root)].p=seq[RC(root)].p=seq[root].p;
      seq[root].lazy=-1;
    }
    if(ri<=seq[LC(root)].r)modify(LC(root),le,ri,w);
    else if(le>=seq[RC(root)].l)modify(RC(root),le,ri,w);
    else{
      modify(LC(root),le,seq[LC(root)].r,w);
      modify(RC(root),seq[RC(root)].l,ri,w);
    }
    if(seq[LC(root)].p!=-1&&
       seq[RC(root)].p!=-1&&
       seq[LC(root)].p==seq[RC(root)].p)seq[root].p=seq[LC(root)].p;
    else seq[root].p=-1;
  }
}

void dfs(int root){
  if(seq[root].p!=-1){
    ans[cnt++]=seq[root].p;
    return;
  }
  if(seq[root].l+1==seq[root].r)return;
  dfs(LC(root));
  dfs(RC(root));
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>L;
  for(int i=0;i<n;i++){
    cin>>poster[i]>>poster[n+i];
    disp[i]=poster[i],disp[n+i]=poster[n+i];
  }
  m=disperse(disp,2*n);
  for(int i=0;i<2*n;i++){
    poster[i]=bisearch(poster[i]);
  }
  build(1,0,m-1);
  for(int i=0;i<n;i++){
    modify(1,poster[i],poster[n+i],i);
  }
  dfs(1);
  cout<<disperse(ans,cnt)<<endl;
  return 0;
}
