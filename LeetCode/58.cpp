class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream str(s);
        string word;
        while(str >> word);
        return word.length();
    }
};