//非递归归并
//无回移，合并最长有序序列
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

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
    if(from[i]<from[j])to[k]=from[i++];
    else to[k]=from[j++];
  }
  if(i>=m)while(j<r)to[k++]=from[j++];
  if(j>=r)while(i<m)to[k++]=from[i++];
}

void mergeSort(int arr[],int n){
  //无回移，合并最长有序序列
  //temp为临时中转数组，flag标明当前有序数组存储在哪个数组中
  int *temp = new int[n];
  bool flag=true;
  //获取数组每个连续有序序列的终止位置，并用队列维护
  //实际存的是终止位置的下一位置
  queue<int> que;
  for(int i=1;i<n;i++){
    if(arr[i]<arr[i-1])que.push(i);
  }
  que.push(n);
  while(1){
    //如果队列中只有一个连续有序序列说明已排好序
    if(que.front()==n)break;
    //两段序列可用三个端点区分，其中最左端端点l由上一次合并得到，m,r存在队列中
    int l=0,m,r;
    while(1){
      if(l==n)break;
      m=que.front();
      que.pop();
      //需要处理连续序列段数的奇偶问题
      if(m<n){
        r=que.front(),que.pop();
        flag?mergeArray(arr,l,m,r,temp):mergeArray(temp,l,m,r,arr);
        //更新连续序列
        que.push(r);
      }else{
        //奇数情况
        flag?move(arr,l,m,temp):move(temp,l,m,arr);
        que.push(m);
      }
      l=que.back();
    }
    //已全部合并到另一数组中
    flag=!flag;
  }
  if(!flag)move(temp,0,n,arr);
  delete [] temp;
}

void mergeSort2(int arr[],int n){
  int *temp = new int[n];
  bool flag = true;
  //步长以两倍的速度增加
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
  //mergeSort(arr,n);
  mergeSort2(arr,n);
  printArray(arr,n);
  delete [] arr;
  return 0;
}
