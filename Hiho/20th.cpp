#include <stdio.h>
#include <string.h>
#include <iostream>
#define LC(x) x<<1
#define RC(x) ((x<<1)+1)

using namespace std;

const int maxn=1e5+1;
struct Interval{
  int l,r,s,lazy;
}seq[maxn*4];
int weight[maxn];
int n,q;

void create(int root,int le,int ri){
  seq[root].l=le,seq[root].r=ri,seq[root].lazy=-1;
  if(le==ri){
    seq[root].s=weight[le];
    return;
  }
  int mid=(ri-le)/2+le;
  create(LC(root),le,mid);
  create(RC(root),mid+1,ri);
  seq[root].s=seq[LC(root)].s+seq[RC(root)].s;
}

void modify(int le,int ri,int root,int w){
  if(seq[root].l==le&&seq[root].r==ri){
    seq[root].lazy=w;
    seq[root].s=(seq[root].r-seq[root].l+1)*seq[root].lazy;
  }
  else{
    if(seq[root].lazy!=-1){
      seq[LC(root)].lazy=seq[root].lazy;
      seq[LC(root)].s=(seq[LC(root)].r-seq[LC(root)].l+1)*seq[LC(root)].lazy;
      seq[RC(root)].lazy=seq[root].lazy;
      seq[RC(root)].s=(seq[RC(root)].r-seq[RC(root)].l+1)*seq[RC(root)].lazy;
      seq[root].lazy=-1;
    }
    if(ri<=seq[LC(root)].r)modify(le,ri,LC(root),w);
    else if(le>=seq[RC(root)].l)modify(le,ri,RC(root),w);
    else{
      modify(le,seq[LC(root)].r,LC(root),w);
      modify(seq[RC(root)].l,ri,RC(root),w);
    }
    seq[root].s=seq[LC(root)].s+seq[RC(root)].s;
  }
}

int query(int le,int ri,int root){
  if(seq[root].l==le&&seq[root].r==ri)return seq[root].s;
  if(seq[root].lazy!=-1){
    seq[LC(root)].lazy=seq[root].lazy;
    seq[LC(root)].s=(seq[LC(root)].r-seq[LC(root)].l+1)*seq[LC(root)].lazy;
    seq[RC(root)].lazy=seq[root].lazy;
    seq[RC(root)].s=(seq[RC(root)].r-seq[RC(root)].l+1)*seq[RC(root)].lazy;
    seq[root].lazy=-1;
  }
  if(ri<=seq[LC(root)].r)return query(le,ri,LC(root));
  else if(le>=seq[RC(root)].l)return query(le,ri,RC(root));
  else return query(le,seq[LC(root)].r,LC(root))+query(seq[RC(root)].l,ri,RC(root));
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n;
  for(int i=1;i<=n;i++)cin>>weight[i];
  create(1,1,n);
  cin>>q;
  int op,l,r,w;
  for(int i=0;i<q;i++){
    cin>>op>>l>>r;
    if(op){
      cin>>w;
      modify(l,r,1,w);
    }else{
      cout<<query(l,r,1)<<endl;
    }
  }
  return 0;
}
