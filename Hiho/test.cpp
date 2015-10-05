#include <stdio.h>
#include <string.h>

const int MAX=110000;
int A[MAX],T[2][MAX],N;

int main(){
	freopen("in.txt","r",stdin);
	//freopen("tetx.txt","w",stdout);
	int TASK;
	scanf("%d",&TASK);
	while(TASK--){
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
			scanf("%d",&A[i]);
		for(int v=0;v<2;v++){
			T[v][0]=T[0][N+1]=0;
			T[v][1]=v;
			int e,i,u;
			for(i=2;i<=N+1;i++){
				for(e=u=0;u<2;u++)
					if(T[v][i-2+u]==1) e++;
				if((T[v][i]=A[i-1]-e)<0||T[v][i]>1) {T[v][N+1]=1;break;} 
			}
			if(T[v][N+1]!=0) for(int i=0;i<N+1;i++) T[v][i]=-1; 
		}
		int n=0,e=0;
		for(int i=1;i<=N;i++){
			if(T[0][i]!=0&&T[1][i]!=0) e++;
			if(T[0][i]!=1&&T[1][i]!=1) n++;
		}
		printf("%d ",e);
		for(int i=1;i<=N||(printf("\n")==0);i++)
			if(T[0][i]!=0&&T[1][i]!=0) printf("%d ",i);
		printf("%d ",n);
		for(int i=1;i<=N||(printf("\n")==0);i++)
			if(T[0][i]!=1&&T[1][i]!=1) printf("%d ",i);
	}
	return 0;
}
