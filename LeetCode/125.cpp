class Solution {
public:
    bool isAlphanumeric(char &c){
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') {
            c = c + 'a' - 'A';
            return true;
        }
        if(c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i = 0, len = s.length(), j = len - 1;
        cout << len << endl;
        while(i <= j){
            while(i < len && !isAlphanumeric(s[i])) i++;
            while(j >= 0 && !isAlphanumeric(s[j])) j--;
            if(i == len || j == -1) break;
            if(s[i] == s[j]) i++, j--;
            else return false;
        }
        return true;
    }
};