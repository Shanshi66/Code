#include <bits/stdc++.h>

using namespace std;

const long long MOD = 19999997;

void matrixProd(long long m[4][4], long long p[4][4]){
    long long a00, a01, a10, a11;
    a00 = ((m[0][0] * p[0][0]) % MOD + (m[0][1] * p[1][0]) % MOD) % MOD;
    a01 = ((m[0][0] * p[0][1]) % MOD + (m[0][1] * p[1][1]) % MOD) % MOD;
    a10 = ((m[1][0] * p[0][0]) % MOD + (m[1][1] * p[1][0]) % MOD) % MOD;
    a11 = ((m[1][0] * p[0][1]) % MOD + (m[1][1] * p[1][1]) % MOD) % MOD;
    m[0][0] = a00;
    m[0][1] = a01;
    m[1][0] = a10;
    m[1][1] = a11;
}

long long solve(long long n){
    if(n < 3) return n;
    long long m[4][4] = {{0, 1}, {1, 1}};
    long long prod[4][4] = {{1, 0}, {0, 1}};
    long long ans;
    long long tmp = n - 1;
    while(tmp){
        if(tmp & 1) matrixProd(prod, m);
        matrixProd(m, m); 
        tmp >>= 1;
    }
    ans = (prod[0][1] + prod[1][1]) % MOD;
    return ans;
}

int main(){
    freopen("in.txt", "r", stdin);
    long long n;
    while(cin >> n){
        cout << solve(n) << endl;
    }
    return 0;
}