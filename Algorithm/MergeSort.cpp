#include <cstdio>
#include <iostream>

using namespace std;

int n;

//num[]为要排序的数组，s为起始位置，e为终止位置(不包括在内),flag标识合并好的序列放哪个数组
void mergeSort(int num[],int s,int e,int &flag){
  if(e-s<=1)return;
  int mid=(s+e)/2,nflag;
  mergeSort(num,s,mid,flag);
  mergeSort(num,mid,e,flag);
  int ss=n*(flag^1),ts=n*flag;
  for(int i=ts+s,j=ts+mid,k=0;i<ts+mid||j<ts+e;k++){
    if(i>=ts+mid)num[ss+k]=num[ts+j],j++;
    else if(j>=ts+e)num[ss+k]=num[ts+i],i++;
    else{
      if(num[ts+i]>num[ts+j])num[ss+k]=num[ts+j],j++;
      else num[ss+k]=num[ts+i],i++;
    }
  }
  flag=flag^1;
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>n;
  int *num=new int[n*2];
  for(int i=0;i<n;i++)cin>>num[i];
  int w=0;
  mergeSort(num,0,n,w);
  for(int i=0;i<n||(puts("\n")<0);i++)cout<<num[w*n+i]<<" ";
  delete [] num;
  return 0;
}
