//算法课作业
//求A,B集合的(A-B)+(B-A)

#include <cstdio>
#include <iostream>
#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int a[],int size_a){
  for(int i=0;i<size_a;i++)cout<<a[i]<<" ";
  cout<<endl;
}

bool bi_search(int x,int arr[],int size_arr){
  int l=0,r=size_arr;
  while(l<r){
    int mid=(r-l)/2+l;
    if(arr[mid]<x)l=mid+1;
    else if(arr[mid]==x)return false;
    else r=mid;
  }
  return true;
}

void solve(int a[],int size_a,int b[],int size_b,int c[],int &size_c){
  sort(a,a+size_a);
  sort(b,b+size_b);
  for(int i=0;i<size_a;i++){
    if(bi_search(a[i],b,size_b))c[size_c++]=a[i];
  }
  for(int i=0;i<size_b;i++){
    if(bi_search(b[i],a,size_a))c[size_c++]=b[i];
  }
}

void solve2(int a[],int size_a,int b[],int size_b,int c[],int &size_c){
  sort(a,a+size_a);
  sort(b,b+size_b);
  int i,j;
  for(i=0,j=0;i<size_a&&j<size_b;){
    if(a[i]<b[j])c[size_c++]=a[i++];
    else if(a[i]==b[j])i++,j++;
    else c[size_c++]=b[j++];
  }
  if(i>=size_a)while(j<size_b)c[size_c++]=b[j++];
  if(j>=size_b)while(i<size_a)c[size_c++]=a[i++];
}


int main(){
  freopen("in.txt","r",stdin);
  int size_a,size_b,size_c=0;
  cin>>size_a>>size_b;
  int *a = new int[size_a];
  int *b = new int[size_b];
  int *c = new int[size_a+size_b];
  for(int i=0;i<size_a;i++)cin>>a[i];
  for(int i=0;i<size_b;i++)cin>>b[i];
  //如果AB中有重复元素
  //solve(a,size_a,b,size_b,c,size_c);
  //如果AB中没有重复元素
  solve2(a,size_a,b,size_b,c,size_c);
  printArray(c,size_c);
  delete [] a;
  delete [] b;
  delete [] c;
  return 0;
}
