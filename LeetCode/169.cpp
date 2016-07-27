class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size_nums = nums.size(), major, count = 0;
        for(int i = 0; i < size_nums; i++){
            if(count == 0){
                major = nums[i];
                count = 1;
            }
            else if(nums[i] == major) count++;
            else count--;
        }
        return major;
    }
};

