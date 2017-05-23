/*
题目：地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows == 0 || cols == 0) return 0;
        vector< vector<bool> > visit(rows, vector<bool>(cols, false));
        return dfs(visit, 0, 0, threshold);
    }
    
    int dfs(vector< vector<bool> > &visit, int x, int y, int k){
        int rows = visit.size(), cols = visit[0].size();
        
        if(x >= rows || x < 0) return 0;
        if(y >= cols || y < 0) return 0;
       
        if(visit[x][y]) return 0;
        if(sumDigits(x, y) > k) return 0;
        
        visit[x][y] = true;
        int dir[4][2] = {{-1, 0},{1, 0}, {0, -1},{0, 1}};
        int sum = 0;
        for(int i = 0; i < 4; i++) {
            sum += dfs(visit, x + dir[i][0], y + dir[i][1], k);
        }
        return 1 + sum;
    }
    
    int sumDigits(int x, int y){
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        while(y > 0){
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
};