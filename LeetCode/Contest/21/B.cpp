class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> sum(size, 0);
        for(int i = 0; i < size; i++) {
            if(i == 0) sum[i] = nums[i];
            else sum[i] = sum[i - 1] + nums[i];
        }
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                int total;
                if(i == 0) total = sum[j];
                else total = sum[j] - sum[i - 1];
                if(total == k) return true;
                if(k == 0) return false;
                if(total % k == 0) return true;
            }
        }
        return false;
    }
};