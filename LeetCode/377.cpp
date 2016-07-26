class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size_nums = nums.size();
        if(size_nums == 0) return 0;
        int dp[target + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= target; i++){
            if(i == 0) dp[i] = 1;
            for(int j = 0; j < size_nums && i >= nums[j]; j++){
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};