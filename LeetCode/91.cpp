class Solution {
public:
    int numDecodings(string s){
        int len = s.length();
        if(len == 0) return 0;
        vector<int> decodeWays(len + 1, 0);
        decodeWays[0] = 1;
        for(int i = 1; i < len + 1; i++){
            if(i >= 1 && s[i - 1] != '0') decodeWays[i] += decodeWays[i - 1];
            if(i >= 2 && s[i - 2] != '0'){
                int offset = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                if(offset <= 26) {
                    decodeWays[i] += decodeWays[i - 2];
                }
            }
        }
        return decodeWays[len];
    }
};