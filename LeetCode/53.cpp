class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(i == 0) dp[i] = nums[i];
            else {
                dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};