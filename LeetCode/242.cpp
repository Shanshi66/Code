class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_size = s.size(), t_size = t.size();
        if(s_size != t_size) return false;
        int letters[26] = {0};
        for(int i = 0; i < s_size; i++) letters[s[i] - 'a'] += 1;
        for(int i = 0; i < t_size; i++) letters[t[i] - 'a'] -= 1;
        for(int i = 0; i < 26; i++){
            if(letters[i]) return false;
        }
        return true;
    }
};