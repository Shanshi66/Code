class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ugly_nums;
        set<long long> filter;

        ugly_nums.push_back(1);
        filter.insert(1);
        int start = 0, end = 1;

        const int FACTOR_NUM = 3;
        long long factor[FACTOR_NUM] = {2, 3, 5};
        while(start < end){
            sort(ugly_nums.begin() + start, ugly_nums.begin() + end);
            for(int i = start; i < end; i++){
                if(ugly_nums[i] * factor[0] > (long long)INT_MAX) break;
                for(int j = 0; j < FACTOR_NUM; j++){
                    long long cand = ugly_nums[i] * factor[j];
                    if(cand > (long long)INT_MAX) break;
                    if(filter.find(cand) == filter.end()){
                        ugly_nums.push_back(cand);
                        filter.insert(cand);
                    }
                }
            }
            start = end;
            end = ugly_nums.size();
        }

        cout << ugly_nums.size() << endl;
        sort(ugly_nums.begin(), ugly_nums.end());

        return ugly_nums[n - 1];
    }
};

/*
a, b, c分别表示2, 3, 5下次乘的起始位置
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums;
        int a = 0, b = 0, c = 0;
        ugly_nums.push_back(1);
        while(ugly_nums.size() < n){
            int next = min(ugly_nums[a] * 2, min(ugly_nums[b] * 3, ugly_nums[c] * 5));
            if(next == ugly_nums[a] * 2) a++;
            if(next == ugly_nums[b] * 3) b++;
            if(next == ugly_nums[c] * 5) c++;
            ugly_nums.push_back(next);
        }
        return ugly_nums[n - 1];
    }
};