#include <stdio.h>
#include <iostream>

#define LC(x) (x<<1)
#define RC(x) ((x<<1)|1)

using namespace std;

const int maxn =1e5+1;
struct Interval{
  int l,r,addy,sety;
  int sum;
}seq[maxn*4];
int n,m;
int price[maxn];

void build(int root,int le,int ri){
  seq[root].l=le,seq[root].r=ri;
  seq[root].addy=0;
  seq[root].sety=-1;
  if(le==ri){
    seq[root].sum=price[le];
    return;
  }
  int mid=(ri-le)/2+le;
  build(LC(root),le,mid);
  build(RC(root),mid+1,ri);
  seq[root].sum=seq[LC(root)].sum+seq[RC(root)].sum;
}

void pushdown(int root){
  if(seq[root].l!=seq[root].r){
    //必须先处理sety！
    //如果孩子有sety标记的话，当一个addy标记到来时，孩子就有可能有两个标记
    //有两个标记的话，处理sety和addy就有差别了。
    if(seq[root].sety!=-1){
      seq[LC(root)].sety=seq[RC(root)].sety=seq[root].sety;
      seq[LC(root)].addy=seq[RC(root)].addy=0;//覆盖addy
      seq[LC(root)].sum=(seq[LC(root)].r-seq[LC(root)].l+1)*seq[LC(root)].sety;
      seq[RC(root)].sum=(seq[RC(root)].r-seq[RC(root)].l+1)*seq[RC(root)].sety;
      seq[root].sety=-1;
    }
    if(seq[root].addy!=0){
      seq[LC(root)].addy+=seq[root].addy;
      seq[RC(root)].addy+=seq[root].addy;
      //使用父亲的addy更新sum而不是自己的addy
      seq[LC(root)].sum+=(seq[LC(root)].r-seq[LC(root)].l+1)*seq[root].addy;
      seq[RC(root)].sum+=(seq[RC(root)].r-seq[RC(root)].l+1)*seq[root].addy;
      seq[root].addy=0;
    }
  }
}

void modify(int root,int op,int le,int ri,int d){
  //cout<<root<<" "<<op<<" "<<le<<" "<<ri<<endl;
  pushdown(root);
  if(seq[root].l==le&&seq[root].r==ri){
    if(op)seq[root].sety=d,seq[root].sum=(seq[root].r-seq[root].l+1)*d;
    else seq[root].addy=d,seq[root].sum+=(seq[root].r-seq[root].l+1)*d;
    return;
  }
  else{
    if(ri<=seq[LC(root)].r)modify(LC(root),op,le,ri,d);
    else if(le>=seq[RC(root)].l)modify(RC(root),op,le,ri,d);
    else{
      modify(LC(root),op,le,seq[LC(root)].r,d);
      modify(RC(root),op,seq[RC(root)].l,ri,d);
    }
    seq[root].sum=seq[LC(root)].sum+seq[RC(root)].sum;
  }
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n>>m;
  for(int i=0;i<=n;i++)cin>>price[i];
  build(1,0,n);
  int op,l,r,d;
  for(int i=0;i<m;i++){
    cin>>op>>l>>r>>d;
    modify(1,op,l,r,d);
    cout<<seq[1].sum<<endl;
  }
}
