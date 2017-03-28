/*
dp[i][j]，以第i个数为结尾，和模为j的长度大于2的序列是否存在

注意特殊情况！！！
1. k < 0, k == 0
2. n == 0
3. sum < k,如果k非常大会爆内存
4. 空间优化
*/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 2) return false;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0 && i < n - 1 && nums[i + 1] == 0) {
                return true;
            }
        }
        if(k == 0) return false;
        if(k < 0) k = -k;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum < k) return false;
        if(sum == k) return true;
        bool ans = false;

        vector< vector<bool> > dp(2, vector<bool>(k, false));
        for(int i = 1; i < n; i++) {
            int before = i % 2, after = (i - 1) % 2;
            dp[after][(nums[i] + nums[i - 1]) % k] = true;
            for(int j = 0; j < k; j++) {
                if(dp[before][j]) {
                    dp[after][(j + nums[i]) % k] = true;
                }
            }
            if(dp[after][0]) {
                ans = true;
                break;
            }
        }
        return ans;
    }
};