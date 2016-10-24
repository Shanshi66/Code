/*
错误代码，乱序也可以
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_len = s.length(), p_len = p.length();
        for(int i = 0; i < s_len; i++){
            if(anagramJudge(s, s_len, i, p, p_len)) ans.push_back(i);
        }
        return ans;
    }
    bool anagramJudge(string s, int s_len, int start, string p, int p_len){
        bool flag = false;
        for(int i = 0; i < p_len; i++){
            int j;
            for(j = 0; j < p_len; j++){
                int index_p = i - j < 0 ? i - j + p_len : i - j;
                int index_s = (start + j) % s_len;
                if(s[index_s] != p[index_p]) break;
            }
            if(j == p_len){
                flag = true;
                break;
            }
        }
        return flag;
    }
};