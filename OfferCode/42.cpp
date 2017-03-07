/*
题目：输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。

思路：两个指针，一前一后，如果当前所指的两个数和小于sum，left向后指，如果大于，right向前挪，如果等于计算当前的乘积
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2) return vector<int>();
        vector<int> res(2, 0);
        bool flag = false;
        int prod = INT_MAX;
        int left = 0, right = array.size() - 1;
        while(left < right) {
            int tmp = array[left] + array[right];
            if(tmp > sum) right--;
            else if(tmp < sum) left++;
            else {
                int curProd = array[left] * array[right];
                if(curProd < prod) {
                    flag = true;
                    prod = curProd;
                    res[0] = array[left];
                    res[1] = array[right];
                }
                left++;
            }
        }
        if(flag) return res;
        else return vector<int>();
    }
};
