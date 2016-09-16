/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
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
        map<pair<int, int>, int> ans_set;
        for(int i = 0; i < envelopes_amount; i++){
            ans_set[envelopes[i]] = 1;
            for(int j = i - 1; j >= 0; j--){
                if(envelopes[j].first < envelopes[i].first && 
                   envelopes[j].second < envelopes[i].second){
                    ans_set[envelopes[i]] = max(ans_set[envelopes[i]], 1 + ans_set[envelopes[j]]);
                }
            }
        }
        int ans = 0;
        for(auto iter = ans_set.begin(); iter != ans_set.end(); iter++){
            ans = max(ans, iter->second);
        }
        return ans;
    }
};