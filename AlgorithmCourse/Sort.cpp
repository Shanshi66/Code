#include <stdio.h>
#include <algorithm>

using namespace std;

void printArray(int A[],int len){
  for(int i=0;i<len;i++){
    printf("%d ",A[i]);
  }
  printf("\n");
}

bool cmp(int a,int b){
  return a>b;
}

int main(){
  int A[7]={5,1,2,6,4,3,9};
  sort(A+2,A+5,cmp);
  printArray(A,7);
  sort(A,A+7,cmp);
  printArray(A,7);
  sort(A,A+7);
  printArray(A,7);
  return 0;
}
