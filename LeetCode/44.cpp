class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        vector< vector<int> > dp(s_len, vector<int>(p_len, -1));
        int ret = dfs(dp, 0, s, 0, p);
        if(ret == 1) return true;
        return false;
    }
    int dfs(vector< vector<int> > &dp, int sp, const string &s, int pp, const string &p) {
        if(sp >= s.length() && pp >= p.length()) return 1;
        if(sp >= s.length() && pp < p.length()){
            for(int i = pp; i < p.length(); i++) {
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        if(sp < s.length() && pp >= p.length()) return 0;
        if(dp[sp][pp] != -1) return dp[sp][pp];
        int flag = 0;
        if(p[pp] == '*') {
            for(int i = sp; i <= s.length(); i++) {
                int ret = dfs(dp, i, s, pp + 1, p);
                if(ret == 1) {
                    flag = 1;
                    break;
                }
            }
        }
        else if (p[pp] == '?') {
            int ret = dfs(dp, sp + 1, s, pp + 1, p);
            if(ret == 1) flag = 1;
        }
        else {
            if(s[sp] == p[pp]) {
                int ret = dfs(dp, sp + 1, s, pp + 1, p);
                if(ret == 1) flag = 1;
            }
        }
        return dp[sp][pp] = flag;
    }
};