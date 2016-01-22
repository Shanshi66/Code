#include <stdio.h>

int partition(int A[],int l,int r){
  int temp=A[l];
  int first=l,last=r-1;
  while(first<last){
    while(A[last]>temp&&first<last)last--;
    if(first<last)A[first]=A[last],first++;
    while(first<last&&A[first]<temp)first++;
    if(first<last)A[last]=A[first],last--;
  }
  A[first]=temp;
  return first;
}

void quickSort(int A[],int l,int r){
  if(l<r-1){
    int m=partition(A,l,r);
    quickSort(A,l,m);
    quickSort(A,m+1,r);
  }
}

int main(){
  int A[7]={5,1,2,6,4,3,10};
  quickSort(A,0,7);
  for(int i=0;i<7;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  return 0;
}
