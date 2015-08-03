#include <stdio.h>
#include <string.h>
#include <iostream>
#define LC(x) ((x<<1)+1)
#define RC(x) ((x<<1)+2)
using namespace std;

const int maxn=1e6+1;
struct Interval{
  int l,r,min;
}seq[maxn*4];
int n,q,weight[maxn];

void build(int le,int ri,int root){
  seq[root].l=le,seq[root].r=ri;
  if(le==ri){
    seq[root].min=weight[le];
    return;
  }
  int mid=(ri-le)/2+le;
  build(le,mid,LC(root));
  build(mid+1,ri,RC(root));
  seq[root].min=min(seq[LC(root)].min,seq[RC(root)].min);
}

int query(int root,int le,int ri){
  //  cout<<seq[root].l<<" "<<seq[root].r<<" "<<le<<" "<<ri<<endl;
  if(seq[root].l==le&&seq[root].r==ri)return seq[root].min;
  if(seq[LC(root)].r>=ri)return query(LC(root),le,ri);
  else if(seq[RC(root)].l<=le)return query(RC(root),le,ri);
  else return min(query(LC(root),le,seq[LC(root)].r),query(RC(root),seq[RC(root)].l,ri));
}

void update(int root,int p,int w){
  if(seq[root].l==p&&seq[root].r==p){
    seq[root].min=w;
    return;
  }
  if(seq[LC(root)].r>=p)update(LC(root),p,w);
  if(seq[RC(root)].l<=p)update(RC(root),p,w);
  seq[root].min=min(seq[LC(root)].min,seq[RC(root)].min);
}

int main(){
  freopen("in.txt","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&weight[i]);
  build(0,n-1,0);
  scanf("%d",&q);
  int op,a,b;
  for(int i=0;i<q;i++){
    scanf("%d%d%d",&op,&a,&b);
    if(op)update(0,--a,b);
    else printf("%d\n",query(0,--a,--b));
  }
}
