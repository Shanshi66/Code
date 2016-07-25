class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size_nums = nums.size();
        int i = 0, j = size_nums - 1, count = 0;
        while(i <= j){
            if(nums[i] == val){
                count++;
                while(nums[j] == val && i < j) j--, count++;
                swap(nums[i++], nums[j--]);
            }else i++;
        }
        return size_nums - count;
    }
};