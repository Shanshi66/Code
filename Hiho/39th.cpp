#include <cstdio>
#include <iostream>

using namespace std;

long long cnt=0;

void printArray(int arr[],int size_arr){
  for(int i=0;i<size_arr;i++)cout<<arr[i]<<" ";
  cout<<endl;
}

void move(int from[],int l,int r,int to[]){
  for(int i=l;i<r;i++)to[i]=from[i];
}

void mergeArray(int from[],int l,int m,int r,int to[]){
  int k=l,i,j;
  for(i=l,j=m;i<m&&j<r;k++){
    if(from[i]>from[j])to[k]=from[i++],cnt+=r-j;
    else to[k]=from[j++];
  }
  if(i>=m)while(j<r)to[k++]=from[j++];
  if(j>=r)while(i<m)to[k++]=from[i++];
}

void mergeSort(int arr[],int n){
  int *temp = new int[n];
  bool flag = true;
  for(int step=1;step<n;step<<=1){
    int l=0,m,r;
    while(l<n){
      m=l+step,r=m+step;
      if(m>n)flag?move(arr,l,n,temp):move(temp,l,n,arr);
      else if(r>n)flag?mergeArray(arr,l,m,n,temp):mergeArray(temp,l,m,n,arr);
      else flag?mergeArray(arr,l,m,r,temp):mergeArray(temp,l,m,r,arr);
      l=r<n?r:n;
    }
    flag=!flag;
  }
  if(!flag)move(temp,0,n,arr);
  delete [] temp;
}

int main(){
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  int *arr = new int[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  mergeSort(arr,n);
  cout<<cnt<<endl;
  delete [] arr;
  return 0;
}

