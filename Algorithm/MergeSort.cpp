#include <cstdio>
#include <iostream>

using namespace std;

int n;

//num[]为要排序的数组长度为2n
//s为起始位置，e为终止位置(不包括在内),flag标识当前合并好的序列放哪个数组
//d的作用是控制树的深度，使其为lgN取上整
int mergeSort(int num[],int s,int e,int flag,int d){
  if(d==0){
    int ts=n*flag;
    if(e-s==2)if(num[ts+s]>num[ts+s+1])swap(num[ts+s+1],num[ts+s]);
    return flag;
  }
  int mid=(s+e)/2,nflag;
  nflag=mergeSort(num,s,mid,flag,d-1);
  nflag=mergeSort(num,mid,e,flag,d-1);
  int ts=nflag*n,ss=(nflag^1)*n;
  for(int i=ts+s,j=ts+mid,k=0;i<ts+mid||j<ts+e;k++){
    if(i>=ts+mid)num[ss+s+k]=num[j],j++;
    else if(j>=ts+e)num[ss+s+k]=num[i],i++;
    else{
      if(num[i]>num[j])num[ss+s+k]=num[j],j++;
      else num[ss+s+k]=num[i],i++;
    }
  }
  return nflag^1;
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n;
  int *num=new int[n*2];
  for(int i=0;i<n;i++)cin>>num[i];
  int w=0,temp=n,depth=0;
  while(temp){
    if(temp&1)depth=w;
    temp>>=1,w++;
  }
  w=mergeSort(num,0,n,0,depth);
  for(int i=0;i<n||(puts("\n")<0);i++)cout<<num[w*n+i]<<" ";
  delete [] num;
  return 0;
}
