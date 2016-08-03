#include <iostream>

using namespace std;

const int MOD = 12357;
int M[8][8] = {{0,0,0,0,0,0,0,1},
               {0,0,0,0,0,0,1,0},
               {0,0,0,0,0,1,0,0},
               {0,0,0,0,1,0,0,1},
               {0,0,0,1,0,0,0,0},
               {0,0,1,0,0,0,0,0},
               {0,1,0,0,0,0,0,1},
               {1,0,0,1,0,0,1,0}};

void matrixProduction(int A[8][8], int B[8][8]){
    int tmp[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            int sum = 0;
            for(int k = 0; k < 8; k++){
                sum = (sum + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
            tmp[i][j] = sum;
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) A[i][j] = tmp[i][j];
    }
}

void print(int A[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(int n){
    int prod[8][8];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) {
            if(i == j) prod[i][j] = 1;
            else prod[i][j] = 0;
        }
    }
    while(n){
        if(n & 1) matrixProduction(prod, M);
        matrixProduction(M, M);
        n >>= 1;
    }
    return prod[7][7];
}

int main(){
    int n;
    cin >> n;
    if(n & 1) cout << 0 << endl;
    else{
        cout << solve(n) << endl;   
    }
    return 0;
}