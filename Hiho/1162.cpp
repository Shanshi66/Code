#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 12357;
const int MAXM = 128;
int M[MAXM][MAXM];
int n, k, m;

void matrixProduction(int A[][MAXM], int B[][MAXM]){
    int tmp[MAXM][MAXM];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int k = 0; k < m; k++){
                sum = (sum + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
            tmp[i][j] = sum;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++) A[i][j] = tmp[i][j];
    }
}

void print(int A[MAXM][MAXM]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(int n){
    int prod[MAXM][MAXM];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++) {
            if(i == j) prod[i][j] = 1;
            else prod[i][j] = 0;
        }
    }
    while(n){
        if(n & 1) matrixProduction(prod, M);
        matrixProduction(M, M);
        n >>= 1;
    }
    return prod[m - 1][m - 1];
}

/*
    在第i行从左往右放，枚举三种方式：
    1. 不放，则第i-1行必为1，x << 1, (y << 1) + 1,往右移一列相当度将原来的x, y左移
    2. 竖着放，则第i - 1必为0，(x << 1) + 1, y << 1
    3. 横着放，第i - 1行两个1，(x << 2) + 3, (y << 2) + 3
*/

void dfs(int x, int y, int col){
    if(col == k) M[y][x] = 1;
    else{
        dfs(x << 1, (y << 1) + 1, col + 1);
        dfs((x << 1) + 1, y << 1, col + 1);
        if(col + 2 <= k) dfs((x << 2) + 3, (y << 2) + 3, col + 2);
    }
}

int main(){
    cin >> k >> n;
    m = 1 << k;
    memset(M, 0, sizeof(M));
    dfs(0, 0, 0);
    if((k * n) & 1) cout << 0 << endl;
    else{
        cout << solve(n) << endl;   
    }
    return 0;
}