class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis; int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                lis.push_back(nums[i]);
                count++;
            } else {
                if(nums[i] > lis[count - 1]) {
                    lis.push_back(nums[i]);
                    count++;
                } else {
                    int index = binarySearchUpbound(lis, 0, count - 1, nums[i]);
                    lis[index] = nums[i];
                }
            }
        }
        return count;
    }
    int binarySearchUpbound(vector<int> lis, int l, int r, int x) {
        while(l < r) {
            int m = (l + r) / 2;
            if(lis[m] < x) l = m + 1;
            else r = m;
        }
        return r;
    }
};