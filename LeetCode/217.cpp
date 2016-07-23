class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> nums_appear;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
            if(nums_appear.find(*iter) != nums_appear.end())return true;
            nums_appear.insert(*iter);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> nums_appear;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
            nums_appear.insert(*iter);
        }
        if(nums.size() != nums_appear.size())return true;
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> nums_appear;
        int size_nums = nums.size();
        for(int i = 0; i < size_nums; i++){
            nums_appear.insert(nums[i]);
            if(i + 1 > nums_appear.size()) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return false;
        sort(nums.begin(), nums.end());
        for(vector<int>::iterator iter = nums.begin() + 1; iter != nums.end(); iter++){
            if(*iter == *(iter - 1)) return true;
        }
        return false;
    }
};