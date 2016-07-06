#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 1000005;
const int MOD = 1000000007;
long long fn[N];

int main(){
    int t, tt=0, n;
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    fn[0]=fn[1]=1;
    for(int i=2; i<N; i++)fn[i]=(fn[i-1]+((i-1)*fn[i-2])%MOD)%MOD;
    while(t--){
        scanf("%d", &n);
        printf("Case #%d:\n%d\n", ++tt, fn[n]);
    }
    return 0;
}
