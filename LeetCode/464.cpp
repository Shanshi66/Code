/*
    记忆化搜索，以二进制标志状态
*/
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
        const int N = 20;
        int dp[1 << N];
        bool used[N];
        memset(dp, -1, sizeof(dp));
        memset(used, 0, sizeof(used));
        return dfs(used, dp, maxChoosableInteger, desiredTotal);
    }
    bool dfs(bool used[], int dp[], int n, int left){
        int index = getIndex(used, n);
        if(dp[index] != -1) return dp[index];
        bool flag = false;
        for(int i = 0; i < n; i++){
            if(flag) break;
            if(used[i]) continue;
            used[i] = true;
            if(left - i - 1 <= 0) flag = true;
            else if(!dfs(used, dp, n, left - i - 1)) flag = true;
            used[i] = false;
        }
        return dp[index] = flag;
    }
    int getIndex(bool used[], int n){
        int index = 0;
        for(int i = 0; i < n; i++){
            if(used[i]) index |= (1 << i);
        }
        return index;
    }
};