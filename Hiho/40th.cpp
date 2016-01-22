#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const double EPS=1e-6;
double a,b,c,x,y;

double abso(double x){
  if(x>=0)return x;
  else return -x;
}

bool isZero(double a){
  if(abso(a)<EPS)return true;
  else return false;
}

double f(double t){
  return (t-x)*(t-x)+(a*t*t+b*t+c-y)*(a*t*t+b*t+c-y);
}

double triSearch(double l,double r){
  double lm,rm;
  while(!isZero(l-r)){
    lm=l+(r-l)/3,rm=l+(r-l)*2/3;
    if(f(lm)<=f(rm))r=rm;
    else l=lm;
  }
  return l;
}

int main(){
  freopen("in.txt","r",stdin);
  cin>>a>>b>>c>>x>>y;
  if(isZero(a)){
    printf("%.3f\n",abs(y-b*x-c)/sqrt(1+b*b));
  }
  else{
    double m=-b/2/a,n;
    if(x<m) n=triSearch(x,m);
    else n=triSearch(m,x);
    printf("%.3f\n",sqrt(f(n)));
  }
  return 0;
}
