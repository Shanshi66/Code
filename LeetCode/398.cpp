/*
    MLE answer
*/

class Solution {
public:
    vector< pair<int, int> > *num_indexs;
    map<int, pair<int, int> > *num_seg;
    Solution(vector<int> nums) {
        num_indexs = new vector< pair<int, int> >(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            (*num_indexs)[i] = make_pair(nums[i], i);
        }
        sort(num_indexs->begin(), num_indexs->end(), cmp);
        num_seg = new map<int, pair<int, int> >;
        int cur;
        for(int i = 0; i <= nums.size(); i++) {
            if(i == 0) {
                cur = (*num_indexs)[i].first;
                (*num_seg)[cur] = make_pair(i, i);
            } else if(i == nums.size()) {
                (*num_seg)[cur].second = i - 1;
            } else {
                if((*num_indexs)[i].first != cur) {
                    (*num_seg)[cur].second = i - 1;
                    (*num_seg)[(*num_indexs)[i].first] = make_pair(i, i);
                    cur = (*num_indexs)[i].first;
                }
            }
        }
    }

    ~Solution() {
        delete [] num_indexs;
        delete [] num_seg;
    }

    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }
    
    int pick(int target) {
        int cnt = (*num_seg)[target].second - (*num_seg)[target].first + 1;
        int index = rand() % cnt + (*num_seg)[target].first;
        return (*num_indexs)[index].second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

class Solution {
public:
    vector<int> nums;
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    int pick(int target) {
        int count = 0, res = 0, size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] != target) continue;
            count++;
            if(rand() % count == 0) {
                res = i;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */