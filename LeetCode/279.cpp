class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        vector<int> squre_number;
        for(int i = 1; i <= n; i++) {
            int squre = i * i;
            if(squre > n) break;
            squre_number.push_back(squre);
            dp[squre] = 1;
        }
        if(dp[n] == 1) return dp[n];
        for(int i = 1; i <= n; i++) {
            if(dp[i] == 1) continue;
            for(int j = 0; j < squre_number.size(); j++) {
                int left = i - squre_number[j];
                if(left < 0) break;
                dp[i] = min(dp[i], 1 + dp[left]);
            }
        }
        return dp[n];
    }
};