/*
题目：给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

/*
思路：单调队列， 队列中维护递减的序列，每添加一个元素，如果该元素比队尾的元素大，弹出队尾元素直到队尾元素比新加的元素大，同时看队首的元素是否还在窗口中，如果不在弹出。
*/


class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        list<pair<int, unsigned int>> decreaseQueue;
       	vector<int> result;
        int len = num.size();
        for(unsigned int i = 0; i < len; i++) {
           	while(!decreaseQueue.empty() && decreaseQueue.back().first < num[i]) decreaseQueue.pop_back();
            decreaseQueue.push_back(make_pair(num[i], i));
            if(decreaseQueue.front().second + size <= i) decreaseQueue.pop_front();
            if(i >= size - 1) result.push_back(decreaseQueue.front().first);
        }
        return result;
    }
};