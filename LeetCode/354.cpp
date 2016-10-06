/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/


/*
第一种做法TLE。在DP的基础上做优化，在每个相同的first序列上二分。
*/

class Solution {
public:
    static bool lessThan(const pair<int, int> &a, const pair<int, int> &b){
        if(a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int envelopes_amount = envelopes.size();
        if(envelopes_amount == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), lessThan);
        // for(auto it: envelopes){
        //     cout << it.first << " " << it.second << endl;
        // }
        map<int, int> ans_set;
        map<int, pair<int, int>> starts_ends;
        for(int i = 0; i < envelopes_amount; i++){
            if(starts_ends.find(envelopes[i].first) != starts_ends.end()){
                starts_ends[envelopes[i].first].second = i;
            }else{
                starts_ends[envelopes[i].first] = make_pair(i, i);
            }
        }
        for(int i = 0; i < envelopes_amount; i++){
            ans_set[i] = 1;
            auto iter = starts_ends.find(envelopes[i].first);
            if(iter == starts_ends.begin()) continue;
            for(auto it = iter; it != starts_ends.begin(); ){
                // cout << i << " " << it->first << " " << endl;
                // cout << envelopes[i].first << " " << it->second.first << " " << it->second.second << endl;
                it--;
                // cout << it->first << endl;
                if(envelopes[it->second.first].second < envelopes[i].second){
                    // cout << envelopes[i].first << " " << it->second.first << endl;
                    int t = binarySearch(envelopes, it->second.first, it->second.second, i);
                    // cout << t << endl;
                    ans_set[i] = max(ans_set[i], 1 + ans_set[t]);
                    // cout << ans_set[i] << endl;
                }
            }
        }
        int ans = 0;
        for(auto iter = ans_set.begin(); iter != ans_set.end(); iter++){
            ans = max(ans, iter->second);
        }
        return ans;
    }
    int binarySearch(const vector< pair<int, int> >& envelopes, int l, int r, int x){
        while(l <= r){
            int m = (l + r) / 2;
            if(envelopes[m].second >= envelopes[x].second) r = m - 1;
            else l = m + 1;
        }
        return l - 1;
    }
};

/*
采用nlgn求最长上升子序列的做法，贪心
1. 维护一个上升的序列collector
2. 每种可能长度维护一个尽可能小的最大值
该方法相当于在一个collector种维护了多种长度最小的最后一个值
*/

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int envelopes_amount = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return (a.first < b.first) || (a.first == b.first && a.second > b.second);
        });
        vector<int> collector;
        for(int i = 0; i < envelopes_amount; i++){
            auto iter = lower_bound(collector.begin(), collector.end(), envelopes[i].second);
            if(iter == collector.end()) collector.push_back(envelopes[i].second);
            else {
                if(*iter > envelopes[i].second) *iter = envelopes[i].second;
            }
        }
        return collector.size();
    }
};