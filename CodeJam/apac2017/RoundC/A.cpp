#include <bits/stdc++.h>

using namespace std;

const int R = 22, C = 22;
int r, c, sr, sc, s;
double p, q;
bool graph[R][C];
int visit[R][C];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
double ans;

double cal(double p, int n){
    double pn = 1;
    for(int i = 0; i < n; i++){
        pn *= p;
    }
    return pn;
}

bool validate(int x, int y){
    if(x >= 0 && x < r && y >= 0 && y < c) return true;
    else return false;
}

void dfs(double result, int x, int y, int step){
    if(step == s){
        ans = max(ans, result);
        // cout << result << endl;
        return;
    }
    double cur_p;
    if(graph[x][y]) cur_p = cal(1 - p, visit[x][y] - 1) * p;
    else cur_p = cal(1 - q, visit[x][y] - 1) * q;

    // cout << x << " " << y << " " << cur_p << " " << endl;

    for(int i = 0; i < 4; i++){
        int xx = x + dir[i][0], yy = y + dir[i][1];
        visit[xx][yy] += 1;
        if(!validate(xx, yy)) continue;
        dfs(result + cur_p, xx, yy, step + 1);
        visit[xx][yy] -= 1;
    }
}

void init(){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            visit[i][j] = 0;
        }
    }
    ans = 0;
}



int main(){
    //freopen("A-small-attempt1.in", "r", stdin);
    
    // freopen("in.txt", "r", stdin);
    //freopen("ans.out", "w", stdout);
    freopen("A-large.in", "r", stdin);
    freopen("large_ans.out", "w", stdout);
    int T, case_cnt = 0;
    cin >> T;
    while(T--){
        cin >> r >> c >> sr >> sc >> s;
        cin >> p >> q;
        init();
        for(int i = 0; i < r; i++){
            for(int j =0; j < c; j++){
                char t; cin >> t;
                if(t == '.') graph[i][j] = false;
                if(t == 'A') graph[i][j] = true;
            }
        }
        for(int i = 0; i < 4; i++){
            int x = sr + dir[i][0], y = sc + dir[i][1];
            if(!validate(x, y)) continue;
            visit[x][y] += 1;
            dfs(0, x, y, 0);
            visit[x][y] -= 1;
        }
        printf("Case #%d: %.7lf\n", ++case_cnt, ans);
    }
    return 0;
}