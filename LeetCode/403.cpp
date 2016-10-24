class Solution {
public:
    bool canCross(vector<int>& stones) {
        int stone_num = stones.size();
        if(stone_num < 2) return true;
        bool dp[1111];
        for(int i = 0; i < stone_num; i++){
            if(i == 0) dp[i] = true;
            else dp[i] = false;
        }
        cout << stone_num << endl;
        cout << 0 << " " << dp[0] << endl;
        for(int i = 1; i < stone_num; i++){
            bool flag = false;
            for(int j = 0; j < i; j++){
                int k = stones[i] - stones[j];
                if(flag) break;
                for(int t = -1; t <= 1; t++){
                    if(j - k - t < 0) continue;
                    if(flag) break;
                    if(dp[j] && dp[j - k - t]) flag = true;
                }
            }
            dp[i] = flag;
            cout << i << " " << dp[i] << endl;
        }
        return dp[stone_num - 1];
    }
};