/*
题目：求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/


/*
解法一：设置静态变量，构造n个对象
*/

class Solution {
public:
    static int sum;
    static int n;
    Solution(){
        sum += n + 1;
    }
    int Sum_Solution(int n) {
        Solution::sum = 0;
        Solution::n = n;
        Solution *solutionSet = new Solution[n];
        delete [] solutionSet;
        return sum >> 1;
    }
};

int Solution::sum = 0;
int Solution::n = 0;