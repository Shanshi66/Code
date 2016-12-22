/*
二分答案
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n == 0) return 0;
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        long long l = sum / m, r = sum;
        while(l <= r) {
            long long mid = (r - l) / 2 + l;
            if(canSplit(nums, mid, m)){
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
    }

    bool canSplit(vector<int> &nums, long long maxSum, int m){
        int n = nums.size();
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxSum) return false;
            sum += nums[i];
            if(sum > maxSum){
                m--;
                sum = nums[i];
            }
        }
        if(m <= 0) return false;
        else return true;
    }
};