#include <bits/stdc++.h>

using namespace std;

struct Loc{
    int x, y, h;
    Loc(){}
    Loc(int xx, int yy, int hh): x(xx), y(yy), h(hh){}
};

bool operator < (const Loc &a, const Loc &b){
    return a.h > b.h;
}


int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

const int MAXN = 50;
int H[MAXN][MAXN];
int r, c;
int sum;

void fill(const Loc &k){
    queue<Loc> que;
    que.push(k);
    bool vis[r][c];
    for(int i = 0; i < r; i++)for(int j = 0; j < c; j++)vis[i][j] = false;
    vis[k.x][k.y] = true;
    int minh = 10000;
    while(!que.empty()){
        Loc tmp = que.front();
        for(int i = 0; i < 4; i++){
            int dx = tmp.x + dir[i][0], dy = tmp.y + dir[i][1];
            if(dx >= r || dx < 0 || dy >= c || dy < 0){
                minh = 0;
                break;
            }
            if(!vis[dx][dy]){
                if(H[dx][dy] > H[k.x][k.y])minh = min(minh, H[dx][dy]);
                else if(H[dx][dy] == H[k.x][k.y]){
                    que.push(Loc(dx, dy, H[dx][dy]));
                    vis[dx][dy] = true;
                }
                else{
                    minh = 0;
                    break;
                }
            }
        }
        que.pop();
        if(!minh)break;
    }
    if(minh){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < r; j++){
                if(vis[i][j]){
                    sum += (minh - H[i][j]);
                    H[i][j] = minh;
                }
            }
        }
    }
}

void init(){
    sum = 0;
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int t, tcase = 0;
    cin >> t;
    while(t--){
        init();
        tcase++;
        cin >> r >> c;
        priority_queue<Loc> heap;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> H[i][j];
                heap.push(Loc(i, j, H[i][j]));
            }
        }
        while(!heap.empty()){
            Loc tmp = heap.top();
            if(tmp.h == H[tmp.x][tmp.y])fill(tmp);
            heap.pop();
        }
        cout << "Case #" << tcase << ": " << sum <<endl;
    }  
    return 0;
}