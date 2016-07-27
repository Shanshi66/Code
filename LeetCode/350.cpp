class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> num_set;
        vector<int> ans_set;
        for(vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++){
            if(num_set.find(*iter) != num_set.end()) num_set[*iter]++;
            else num_set[*iter] = 1;
        }
        for(vector<int>::iterator iter = nums2.begin(); iter != nums2.end(); iter++){
            if(num_set.find(*iter) != num_set.end() && num_set[*iter] > 0) {
                ans_set.push_back(*iter);
                num_set[*iter]--;
            }
        }
        return ans_set;
    }
};