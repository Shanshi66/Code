#include <stdio.h>

void insertSort(int A[],int len){
  for(int j=1;j<len;j++){
    int key = A[j],i=j-1;
    while(i>=0&&A[i]>key){
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=key;
  }
}

int main(){
  int A[7]={5,1,2,6,4,3,9};
  insertSort(A,7);
  for(int i=0;i<7;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
  return 0;
}
