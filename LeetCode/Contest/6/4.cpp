struct Node{
    int x, y, h;
    Node(){}
    Node(int _x, int _y, int _h): x(_x), y(_y), h(_h){}
};

class Solution {
public:
    static bool cmp(const Node &a, const Node &b){
        return a.h < b.h;
    }

    long long fill(const Node &loc, vector< vector<int> > &H, int m, int n){
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        long long sum = 0;
        bool flag[110][110];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                flag[i][j] = false;
            }
        }

        int minh = 20000;
        queue< pair<int, int> > que;
        vector< pair<int, int> > hasVisited;
        que.push(make_pair(loc.x, loc.y));
        flag[loc.x][loc.y] = true;
        hasVisited.push_back(make_pair(loc.x, loc.y));
        while(!que.empty()){
            pair<int, int> cur = que.front();
            que.pop();
            for(int i = 0; i < 4; i++){
                int x = cur.first + dir[i][0], y = cur.second + dir[i][1];
                if(isOut(x, y, m, n)){
                    minh = 0;
                    break;
                }
                if(flag[x][y]) continue;
                if(H[x][y] < H[loc.x][loc.y]){
                    minh = 0;
                    break;
                }else if(H[x][y] > H[loc.x][loc.y]){
                    minh = min(H[x][y], minh);
                }else{
                    flag[x][y] = true;
                    hasVisited.push_back(make_pair(x, y));
                    que.push(make_pair(x, y));
                }
            }
            if(minh == 0)break;
        }
        if(minh){
            for(auto t : hasVisited){
                sum += minh - H[t.first][t.second];
                H[t.first][t.second] = minh;
            }
        }
        return sum;
    }

    bool isOut(int x, int y, int m, int n){
        if(x < 0 || x >= m || y < 0 || y >=n) return true;
        return false;
    }

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m == 0) return 0;
        int n = heightMap[0].size();
        if(n == 0) return 0;
        vector<Node> que;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                que.push_back(Node(i, j,heightMap[i][j]));                
            }
        }
        sort(que.begin(), que.end(), cmp);
        long long ans = 0;
        for(int i = 0; i < m * n; i++){
            if(que[i].h != heightMap[que[i].x][que[i].y]) continue;
            ans += fill(que[i], heightMap, m, n);
        }
        return ans;
    }
};