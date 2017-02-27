/*
题目：连续子数组最大和， 经典题
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        typedef vector<int>::iterator iter;
        int sum = *array.begin(), pre_sum = sum;
        for(iter it = array.begin() + 1; it != array.end(); it++) {
        	pre_sum = max(pre_sum + *it, *it);
            sum = max(sum, pre_sum);
        }
        return sum;
    }
};