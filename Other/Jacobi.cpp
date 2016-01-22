#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  double x[3];
  //init
  for(int i=0;i<3;i++)x[i]=0;
  while(1){
    double xx[3];
    xx[0]=1.0/5*(-12-2*x[1]-x[2]);
    xx[1]=1.0/4*(20-2*x[2]+x[0]);
    xx[2]=1.0/10*(3-2*x[0]+3*x[1]);
    cout<<xx[0]<<" "<<xx[1]<<" "<<xx[2]<<endl;
    if(max(max(xx[0]-x[0],xx[1]-x[1]),xx[2]-x[2])<1e-5)break;
    x[0]=xx[0],x[1]=xx[1],x[2]=x[2];
  }
  return 0;
}
