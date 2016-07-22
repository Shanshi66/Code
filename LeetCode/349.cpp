class Solution {
public:
    string reverseVowels(string s) {
        string vowel, ans;
        int len = s.length();
        for(int i = len - 1; i >= 0; i--){
            if(s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u'||
               s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U'){
                vowel += s[i];
            }
        }
        int len2 = vowel.length();
        if(len2 == 0) return s;
        for(int i = 0, j = 0; i < len; i++){
            if(s[i] == 'a' || s[i] == 'o' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u'||
               s[i] == 'A' || s[i] == 'O' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U'){
                ans += vowel[j++];
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};