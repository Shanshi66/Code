/*
看做一个01背包问题
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum & 1) return false;
        sum  = sum / 2;
        int dp[10000];
        for(int i = 0; i <= sum; i++) dp[i] = 0;
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= 0; j--){
                if(j >= nums[i]){
                    dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                }
            }
        }
        if(dp[sum] == sum) return true;
        return false;
    }
};