class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size_nums = nums.size();
        if(size_nums == 0) return;
        if(k > size_nums) k = k % size_nums;
        reverse(nums, 0, size_nums - k);
        reverse(nums, size_nums - k, size_nums);
        reverse(nums, 0, size_nums);
    }
    void reverse(vector<int> &nums, int s, int t){
        int i = s, j = t - 1;
        while(i <= j)swap(nums[i++], nums[j--]);
    }
};