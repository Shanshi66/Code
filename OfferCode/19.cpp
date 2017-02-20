/*
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

注意：
当最后只有一行或一列时，需特殊处理：
1. 防止重复走
2. 最后一个元素需特殊处理

*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size();
        if(row == 0) return vector<int>();
        int col = matrix[0].size();
        if(col == 0) return vector<int>();
        
        bool isOdd = false;
        int _min = min(row, col);
        if(_min & 1) isOdd = true;
    	
        int circle;
        if(isOdd) circle = _min / 2 + 1;
        else circle = _min / 2;
        
        int x_steps = row - 1, y_steps = col - 1;
        int x = -1, y = -1;
        vector<int> result;
        for(int i = 0; i < circle; i++) {
            y += 1, x += 1;
            for(int j = 0; j < y_steps; j++) {
                result.push_back(matrix[x][y++]);
            }
            for(int j = 0; j < x_steps; j++) {
                result.push_back(matrix[x++][y]);
            }
            for(int j = 0; x_steps > 0 && j < y_steps; j++) {
                result.push_back(matrix[x][y--]);
            }
            for(int j = 0; y_steps > 0 && j < x_steps; j++) {
                result.push_back(matrix[x--][y]);
            }
            x_steps -= 2;
            y_steps -= 2;
        }
        if(isOdd) {
            result.push_back(matrix[x][y]);
        }
        return result;
    }
};