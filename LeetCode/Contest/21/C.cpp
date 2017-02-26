class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        vector<vector<int> > table(26, vector<int>());
        int slen = s.length();
        for(int i = slen - 1; i >= 0; i--) {
            table[s[i] - 'a'].push_back(i);
        }
        string ans(1100, 'z');
        bool flag = false;
        for(auto str: d){
            if(judge(table, str, 0, str.length(), -1)) {
                flag = true;
                if(str.length() > ans.length() || str.compare(ans) < 0) ans = str;
            }
        }
        if(!flag) ans = string();
        return ans;
    }
    bool judge(vector<vector<int> > &table, string str, int begin, int end, int last_index){
        if(begin == end) return true;
        char current_char = str[begin] - 'a';
        int size = table[current_char].size();
        bool flag = false;
        if(size == 0) return false;
        if(table[current_char][size - 1] > last_index)
             flag = judge(table, str, begin + 1, end, table[current_char][size - 1]);
        else {
            int tmp = table[current_char][size - 1];
            table[current_char].pop_back();
            flag = judge(table, str, begin, end, last_index);
            table[current_char].push_back(tmp);
        }
        return flag;
    }
};