class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size_nums = nums.size(), new_len = 0;
        if(size_nums < 2) return size_nums;
        for(int i = 1; i < size_nums; i++){
            if(nums[new_len] != nums[i]) nums[++new_len] = nums[i];
        }
        return new_len + 1;
    }
};