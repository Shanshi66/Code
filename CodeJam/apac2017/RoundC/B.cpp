#include <bits/stdc++.h>

using namespace std;

const int R = 3003;
const int C = 3003;

int graph[R][C];
int sum[R][C];
int r, c, k;
long long ans;


void init(){
    ans = 0; sum[0][0] = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i == 0 && j == 0) sum[i][j] = graph[i][j];
            else if(j == 0) sum[i][j] = sum[i - 1][j] + graph[i][j];
            else if(i == 0) sum[i][j] = sum[i][j - 1] + graph[i][j];
            else{
                sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + graph[i][j];
            }
            //cout << sum[i][j] << " ";
        }
        //cout << endl;
    }
}

int getSum(int len, int i, int j){
    if(i < len && j < len) return sum[i][j];
    else if (i < len) return sum[i][j]  - sum[i][j - len];
    else if(j < len) return sum[i][j] - sum[i - len][j];
    else return sum[i][j] - sum[i - len][j] - sum[i][j - len] + sum[i - len][j - len];
}

void solve(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int l = 0, r = min(i, j) + 1, result = 0;
            while(l <= r){
                int m = (l + r) / 2;
                int square_sum = getSum(m, i, j);
                if(square_sum == 0) l = m + 1, result = m;
                else r = m - 1; 
            }
            //cout << i << " " << j << " " << result << endl;
            ans += result;
        }
    }
    // cout << sum[2][1] << sum[1][1] << sum[2][0] << sum[1][0] << endl;
    // cout << getSum(1, 2, 1) << endl;
}

int main(){
    //freopen("B-small-attempt0.in", "r", stdin);
    
    //freopen("in.txt", "r", stdin);
    //freopen("small_ans.out", "w", stdout);
    freopen("B-large.in", "r", stdin);
    freopen("large_ans.out", "w", stdout);
    int T, case_cnt = 0;
    cin >> T;
    while(T--){
        cin >> r >> c >> k;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                graph[i][j] = 0;
            }
        }
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
        }
        init();
        solve();
        printf("Case #%d: %d\n", ++case_cnt, ans);
    }
    return 0;
}