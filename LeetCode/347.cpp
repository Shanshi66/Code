class Solution {
public:
    struct T{
        int val, freq;
        T(){}
        T(int x, int y): val(x), freq(y){}
        bool operator < (struct T x){
            return freq > x.freq;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> nums_freq;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
            if(nums_freq.find(*iter) == nums_freq.end()) nums_freq[*iter] = 0;
            else nums_freq[*iter]++;
        }
        int size_nums = nums_freq.size();
        if(size_nums == 0) return nums;
        vector<T> t_set;
        for(map<int, int>:: iterator iter = nums_freq.begin(); iter != nums_freq.end(); iter++){
            t_set.push_back(T(iter->first, iter->second));
        }
        sort(t_set.begin(), t_set.end());
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(t_set[i].val);
        }
        return ans;
    }
};