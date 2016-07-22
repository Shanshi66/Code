class Solution {
public:
    string reverseString(string s) {
        string ans;
        for(string::reverse_iterator iter = s.rbegin(); iter != s.rend(); iter++){
            ans += *iter;
        }
        return ans;
    }
};

class Solution {
public:
    string reverseString(string s) {
        int len = s.length(), i = 0, j = len - 1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
        return s;
    }
};