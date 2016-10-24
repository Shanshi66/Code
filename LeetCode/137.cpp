/*
Given an array of integers, every element appears three times except for one. Find that single one.
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, base = 1, nums_size = nums.size();
        for(int i = 0; i < 32; i++){
            int sum = 0;
            for(int j = 0; j < nums_size; j++){
                sum += (nums[j] & base);
                nums[j] >>= 1;
            }
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> stat; int ans;
        for(auto num: nums){
            if(stat.find(num) != stat.end()) stat[num] += 1;
            else stat[num] = 1;
        }
        for(auto iter = stat.begin(); iter != stat.end(); iter++){
            if(iter->second == 1){
                ans = iter->first;
                break;
            }
        }
        return ans;
    }
};