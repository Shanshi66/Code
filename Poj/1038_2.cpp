#include <stdio.h>

const int N = 150, M = 10;
int n, m, k, T, ans;
int mask[N + 2];
int dp[N][1 << M][1 << M];

void maskInit(){
    for(int i = 0; i < n; i++) mask[i] = 0;
    mask[0] = mask[1] = T - 1;
}

void dfs(int x, int y, int cur, int last1 , int last2, int result){
    if(y >= m) return;
    if(y == m && x == n){
        ans = ans > result ? ans : result;
        return;
    }
    if(y == m){
        dfs(x + 1, 0, mask[x + 1], cur, last1, result);
    }
    int lay = 7 << y;
    int stand = 3 << y;
    // if can stand
    if((stand & cur) == 0){
        if((last2 & stand) == 0 && (last1 & stand) == 0){
            dfs(x, y + 2, cur | stand, last1 | stand, last2 | stand, result + 1);
        }
    }
    // if can lay
    if((lay & cur) == 0){
        if((last1 & lay) == 0){
            dfs(x, y + 3, cur | lay, last1 | lay, last2, result + 1);
        }
    }
    // not put
    dfs(x, y + 1, cur, last1, last2, result);
}

void doInit(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < T; j++){
            for(int k = 0; k < T; k++){
                dp[i][j][k] = 0;
            }
        }
    }
}

void dfs(int x, int y, int cur){
    int lay = 7 << y;
    int stand = 3 << y;
    // if can stand
    if((stand & cur) == 0){
        for(int i = 0; i < T; i++){
            if()
        }
    }
    // if can lay
    if((lay & cur) == 0){
        
    }
    // not put
    dfs(x, y + 1, cur, last1, last2, result);
}

void solve(){
    dpInit();
    for(int i = 2; i < n; i++){
        dfs(i, 0, mask[i]);
    }
}

int main(){
    int tcase;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    scanf("%d", &tcase);
    while(tcase--){
        scanf("%d%d%d", &n, &m, &k);
        T = 1 << m;
        maskInit();
        for(int i = 0; i < k; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            mask[x + 1] |= 1 << (y - 1);
        }
        solve();
        dfs(2, 0, mask[2], mask[1], mask[0], 0);
        printf("%d\n", ans);
    }
    return 0;
}