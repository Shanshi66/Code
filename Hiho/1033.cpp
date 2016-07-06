#include <cstdio>
#include <iostream>

using namespace std;

const int N = 20;
const int T = 100;
const long long MOD = 1e9+7;
long long dp[10][N][2*T+1];
int cnt[10][N][2*T+1];
long long base[N];
long long l, r;
int k;

long long cross_sum(long long t){
    int num[N], len=0;
    while(t){
        num[len++] = t%10;
        t = t/10;
    }
    long long sum=0 ;
    for(int i=0; i<len; i++){
        for(int j=1; j<num[i]; j++){
            sum = (sum + dp[j][i+1][k+T])%MOD;
        }
    }
    return sum;
}

int main(){
    // freopen("in.txt", "r", stdin);
    for(int i=1; i<10; i++){
        dp[i][1][i+T] = i;
        cnt[i][1][i+T] = 1;
    }
    for(int i=0; i<=18; i++){
        if(i==0)base[i]=1;
        else base[i] = 10*base[i-1];
    }
    for(int j=2; j<N; j++){
        for(int i=1; i<10; i++){
            for(int s=-T; s<=T; s++){
                for(int t=0; t<10; t++){
                    cnt[i][j][s+T] = cnt[i][j][s+T] + cnt[t][j-1][i-s+T];
                    dp[i][j][s+T] = (dp[i][j][s+T] + dp[t][j-1][i-s+T]+(i*cnt[t][j-1][i-s+T]*base[i])%MOD)%MOD;
                }
            }
        }
    }
    cout<<cnt[9][2][0+T]<<endl;
    cin>>l>>r>>k;
    cout<<cross_sum(r)-cross_sum(l)<<endl;
    return 0;
}
