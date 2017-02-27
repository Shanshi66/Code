/*
题目：输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

思路：利用大顶堆存K个数
注意：两个边界问题需处理
1. k = 0时需处理，否则re
2. 数组为空
*/


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(k == 0 || input.size() < k) return res;
        priority_queue<int, vector<int>, less<int>> heap;
      	typedef vector<int>::iterator iter;
        for(iter it = input.begin(); it != input.end(); it++) {
            if(heap.size() < k) heap.push(*it);
            else {
                if(heap.top() > *it) {
                    heap.pop();
                    heap.push(*it);
                }
            }
        }
        while(!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }
        return res;
    }
};