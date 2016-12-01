class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_len = t.length(), s_len = s.length();
        if(s_len == 0) return true;
        if(t_len == 0) return false;
        int ps = 0, pt = 0;
        while(pt < t_len) {
            if(t[pt] == s[ps]) {
                pt++; ps++;
            } else {
                pt++;
            }
        }
        if(ps < s_len) return false;
        return true;
    }
};

/*
大量询问代码，开26 * t长度的数组，存每个字母从第i个位置开始往后的第一次出现位置
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_len = t.length(), s_len = s.length();
        if(s_len == 0) return true;
        if(t_len == 0) return false;
        vector< vector<int> > table(26, vector<int>(t_len, -1));
        for(int i = 0; i < t_len; i++) {
            table[t[i] - 'a'][i] = i;                
        }
        for(int i = 0; i < 26; i++) {
            for(int j = t_len - 2; j >= 0; j--) {
                if(table[i][j] == -1) table[i][j] = table[i][j + 1];
            }
        }
        int b = -1;
        for(int i = 0; i < s_len; i++) {
            b = table[s[i] - 'a'][b + 1];
            if(b == -1 || b >= t_len) return false;
        }
        return true;
    }
};