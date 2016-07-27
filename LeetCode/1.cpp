class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> nums_set;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            nums_set[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            map<int, int>::iterator iter = nums_set.find(target - nums[i]);
            if(iter != nums_set.end() && iter->second != i){
                ans.push_back(i);
                ans.push_back(iter->second);
                break;
            }
        }
        return ans;
    }
};