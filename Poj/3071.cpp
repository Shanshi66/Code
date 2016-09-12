#include <iostream>
#include <cstdio>

using namespace std;

const int N = 7;
const int M = (1 << N);
double p[M][M], dp[M][N];
int n, m;

void init(){
    for(int i = 0; i < m; i++){
        if(i & 1) dp[i][0] = p[i][i - 1];
        else dp[i][0] = p[i][i + 1];
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    while(cin >> n){
        if(n == -1) break;
        m = 1 << n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                cin >> p[i][j];
            }
        }
        init();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                double sum = 0;
                int t = j / (1 << (i + 1));
                for(int k = t * (1 << (i + 1)); k < (t + 1) * (1 << (i + 1)); k++){
                    int s = j / (1 << i);
                    if(k < s * (1 << i) || k >= (s + 1) * (1 << i)){
                        sum += dp[k][i - 1] * p[j][k];
                    }
                }
                dp[j][i] = dp[j][i - 1] * sum;
            }
        }
        int winner = 0; double proba = -1;
        for(int i = 0; i < m; i++){
            // cout << dp[i][n - 1] << endl;
            if(dp[i][n - 1] > proba){
                proba = dp[i][n - 1];
                winner = i;
            }
        }
        // cout << proba << endl;
        cout << winner + 1 << endl;
    }
    return 0;
}