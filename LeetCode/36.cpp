class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool filled[9];
        int row = board.size(), col = board[0].size();
        //valid rows
        for(int i = 0; i < row; i++){
            for(int j = 0; j < 9; j++)filled[j] = false;
            for(int j = 0; j < col; j++){
                if(board[i][j] != '.'){
                    if(filled[board[i][j] - '1']) return false;
                    else filled[board[i][j] - '1'] = true;
                }
            }
        }
        //valid columns
        for(int i = 0; i < col; i++){
            for(int j = 0; j < 9; j++)filled[j] = false;
            for(int j = 0; j < row; j++){
                if(board[j][i] != '.'){
                    if(filled[board[j][i] - '1']) return false;
                    else filled[board[j][i] - '1'] = true;
                }
            }
        }
        //valid grid
        for(int i = 0; i < 9; i++){
            int s_row = i / 3 * 3, s_col = i % 3 * 3;
            for(int j = 0; j < 9; j++) filled[j] = false;
            for(int j = s_row; j < s_row + 3; j++){
                for(int k = s_col; k < s_col + 3; k++){
                    if(board[j][k] != '.'){
                        if(filled[board[j][k] - '1']) return false;
                        else filled[board[j][k] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};