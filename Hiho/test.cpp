#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>

using namespace std;
#define N -999999999

int array[50050],mark[50050],back[50050];
int n;
int cmax;

void init(){
	for(int i = 0; i <= n; i++){
		mark[i] = back[i] = 0;
	}
	cmax = N;
}

int main(){
	// freopen("in.txt", "r", stdin);
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&array[i]);
			if(i==1){
				mark[i]=array[i];
			}
			else{
				if(mark[i-1]<0) mark[i]=array[i];
				else
					mark[i]=mark[i-1]+array[i];
			}
		}
		for(int i=n;i!=0;i--)
		{
			if(i==n){
				back[i]=array[i];
			}
			else {
				if(back[i+1] < 0) back[i]=array[i];
				else back[i]=back[i+1]+array[i];
			}
		}
		for(int i=2;i!=n+1;i++){
			 mark[i]=max(mark[i],mark[i-1]);
		}
		for(int i=n-1;i!=0;i--){
			 back[i]=max(back[i],back[i+1]);
		}
		for(int i=1;i<n;i++){
			cmax=max(mark[i]+back[i+1],cmax);
		}
		printf("%d\n",cmax);
	}
	return 0;
}

