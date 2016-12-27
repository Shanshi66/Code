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



/*
基于这样一个事实：存在两个'*'时，第一个'*'如果有两种匹配方式，和第二个'*'有两种匹配方式等同．只需考虑后一个'*'能否匹配．
如
acabcbca
a*b*a
第一个'*'有两种匹配方式，ca, cabc. 只需匹配到第一个ｂ就行
第二个'*'匹配cbc
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        int i = 0, j = 0, asterisk = -1, match;
        while (i < m) {
            if (j < n && p[j] == '*') {
                match = i; 
                asterisk = j++;
            }
            else if (j < n && (s[i] == p[j] || p[j] == '?')) {
                i++; 
                j++;
            }
            else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            }
            else return false;
        }
        while (j < n && p[j] == '*') j++;
        return j == n;
    }
};


/*
非递归写法
*/

public class Solution {
    public boolean isMatch(String s, String p) {
        boolean[][] match=new boolean[s.length()+1][p.length()+1];
        match[s.length()][p.length()]=true;
        for(int i=p.length()-1;i>=0;i--){
            if(p.charAt(i)!='*')
                break;
            else
                match[s.length()][i]=true;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=p.length()-1;j>=0;j--){
                if(s.charAt(i)==p.charAt(j)||p.charAt(j)=='?')
                        match[i][j]=match[i+1][j+1];
                else if(p.charAt(j)=='*')
                        match[i][j]=match[i+1][j]||match[i][j+1];
                else
                    match[i][j]=false;
            }
        }
        return match[0][0];
    }
}

