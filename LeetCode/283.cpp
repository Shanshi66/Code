class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size_num = nums.size(), count = 0;
        for(int i = size_num - 1; i >= 0; i--){
            if(nums[i] == 0){
                for(int j = i + 1; j < size_num - count; j++){
                    nums[j - 1]  = nums[j];
                }
                nums[size_num - count - 1] = 0;
                count++; 
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size_num = nums.size(), count = 0;
        for(int i = 0; i < size_num; i++){
            if(nums[i] == 0) count++;
            else nums[i - count] = nums[i];
        }
        for(int i = size_num - count; i < size_num; i++){
            nums[i] = 0;
        }
    }
};