class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            return a.first + a.second < b.first + b.second;
        }
    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
        int size_s1 = nums1.size(), size_s2 = nums2.size();
        if(!size_s1 || !size_s2) return {};
        size_s1 = min(k, size_s1), size_s2 = min(k, size_s2);
        for(int i = 0; i < size_s1; i++){
            for(int j = 0; j < size_s2; j++){
                pair<int, int> tmp = make_pair(nums1[i], nums2[j]);
                if(heap.size() < k)heap.push(tmp);
                else{
                    pair<int, int> top = heap.top();
                    if(top.first + top.second > tmp.first + tmp.second){
                        heap.pop();
                        heap.push(tmp);
                    }
                }
            }
        }
        vector<pair<int, int>> ans;
        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        return ans;
    }
};

