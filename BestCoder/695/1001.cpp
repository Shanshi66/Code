#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

const int N = 1000005;
const int MOD = 1000000007;
long long fn[N];

int main(){
    //freopen("in.txt", "r", stdin);
    int t, tt=0, n;
    scanf("%d", &t);
    for(int i=0; i<N; i++){
        if(i==0||i==1)fn[i]=1;
        else{
            if(i&1)fn[i]=(fn[i-1]*i)%MOD;
            else fn[i]=(fn[i-1]*i/2)%MOD;
        }
    }
    while(t--){
        scanf("%d", &n);
        long long tmp=fn[n],ans=0, t=n/2;
        for(int i=t*2; i>=0; i-=2){
            ans = (ans + tmp)%MOD;
            tmp = 2*tmp/(n-i+1)/(n-i+2);
        }
        printf("Case #%d:\n%d\n", ++tt, ans);
    }
    return 0;
}
