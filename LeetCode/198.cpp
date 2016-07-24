class Solution {
public:
    int rob(vector<int>& nums) {
        int size_nums = nums.size(), dp[size_nums], ans = 0;
        for(int i = 0; i < size_nums; i++){
            dp[i] = nums[i];
            for(int j = i - 2; j >= 0 && j >= i - 3; j--){
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};