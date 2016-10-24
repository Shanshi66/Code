class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int row = words.size();
        bool flag = true;
        for(int i = 0; i < row; i++){
            string col_string;
            for(int j = 0; j < row; j++){
                if(words[j].length() < i + 1) continue;
                col_string += words[j][i];
            }
            cout << i << " " << words[i] << " " << col_string << endl;
            if(words[i] != col_string) flag = false;
        }
        return flag;
    }
};