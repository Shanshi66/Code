#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;
int n,m;

struct Edge{
  	int to,v,next;
}edge[MAXM];

struct Node{
  	int v,to;
}heap[MAXM*2];

int head[MAXN];
bool vis[MAXN];
int cnt,hcnt;

void init(){
  	memset(head,-1,sizeof(head));
  	memset(vis,false,sizeof(vis));
  	cnt=0,hcnt=0;
}

void add(int from,int to,int val){
  	edge[cnt].to=to;
  	edge[cnt].v=val;
  	edge[cnt].next=head[from];
  	head[from]=cnt++;
}

void heap_insert(int v,int to){
  	heap[++hcnt].v=v,heap[hcnt].to=to;
  	int p=hcnt;
  	while(p>1){
	    if(heap[p].v<heap[p>>1].v)swap(heap[p],heap[p>>1]);
    	else break;
    	p=p>>1;
  	}
}

void heap_drop(){
  	swap(heap[1],heap[hcnt]);
  	hcnt--;
  	int p=1;
  	while(p<=hcnt){
    	int who,lc=p<<1,rc=p<<1|1;
    	if(rc<=hcnt){
      		if(heap[lc].v<heap[rc].v)who=lc;
      		else who=rc;
    	}
    	else if(lc<=hcnt)who=lc;
    	else break;
    	if(heap[who].v<heap[p].v)swap(heap[p],heap[who]);
    	else break;
    	p=who;
  	}
}

int  prim_heap(){
  	int weight=0;
  	int p=1;
  	vis[p]=true;
  	while(--n){
    	for(int i=head[p];i!=-1;i=edge[i].next){
      		if(!vis[edge[i].to])heap_insert(edge[i].v,edge[i].to);
    	}
    	while(vis[heap[1].to])heap_drop();
    	weight+=heap[1].v;
    	p=heap[1].to;
    	vis[p]=true;
  	}
  	return weight;
}

int main(){
  	freopen("in.txt","r",stdin);
  	cin>>n>>m;
  	init();
  	for(int i=0,a,b,c;i<m;i++){
    	cin>>a>>b>>c;
    	add(a,b,c);
    	add(b,a,c);
  	}
  	cout<<prim_heap()<<endl;
  	return 0;
}