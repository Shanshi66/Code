#include <stdio.h>

void bubbleSort(int a[],int len){
  for(int i=0;i<len;i++){
    for(int j=0;j<len-i-1;j++){
      if(a[j]>a[j+1]){
        int temp=a[j+1];
        a[j+1]=a[j];
        a[j]=temp;
      }
    }
  }
}

int main(){
  int a[7]={3,1,5,4,6,9,7};
  bubbleSort(a,7);
  for(int i=0;i<7;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}
