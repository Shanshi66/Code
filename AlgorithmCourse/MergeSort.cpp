#include <stdio.h>

void merge(int a[],int l,int m,int r){
  int *b = new int[r-l];
  int i,j,k;
  for(i=0,j=l,k=m;j<m&&k<r;i++){
    if(a[j]<a[k])b[i]=a[j++];
    else b[i]=a[k++];
  }
  if(j<m)while(j<m)b[i++]=a[j++];
  if(k<r)while(k<r)b[i++]=a[k++];
  for(j=0;j<i;j++)a[l+j]=b[j];
  delete [] b;
}

void mergeSort(int a[],int l,int r){
  if(l<r-1){
    int m=(r-l)/2+l;
    mergeSort(a,l,m);
    mergeSort(a,m,r);
    merge(a,l,m,r);
  }
}

int main(){
  int a[7]={5,1,2,6,4,3,9};
  mergeSort(a,0,7);
  for(int i=0;i<7;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
  return 0;
}
