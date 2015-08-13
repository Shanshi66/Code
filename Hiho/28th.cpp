#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int N=1e5+1;
int heap[N*2];
int cnt;

void adjust_up(int t){
  while(t>1){
    if(heap[t>>1]<heap[t])swap(heap[t>>1],heap[t]),t=t>>1;
    else break;
  }
}

void adjust_down(int root){
  while(root<cnt&&heap[root]!=-1){
    int lc=root<<1,rc=root<<1|1;
    if(heap[lc]>heap[rc]){
      if(heap[lc]>heap[root])swap(heap[root],heap[lc]),root=lc;
      else break;
    }
    else{
      if(heap[rc]>heap[root])swap(heap[root],heap[rc]),root=rc;
      else break;
    }
  }
}

int pop(){
  int ans=heap[1];
  swap(heap[1],heap[cnt-1]);
  heap[--cnt]=-1;
  adjust_down(1);
  return ans;
}


void insert(int w){
  heap[cnt++]=w;
  adjust_up(cnt-1);
}

void init(){
  cnt=1;
  memset(heap,-1,sizeof(heap));
}

int main(){
  freopen("in.txt","r",stdin);
  init();
  int n;
  scanf("%d",&n);
  char temp;
  int w;
  while(n--){
    getchar();//'\n'
    temp=getchar();
    if(temp=='A')scanf("%d",&w),insert(w);
    else printf("%d\n",pop());
  }
  return 0;
}
