/*
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

思路：每次选择最右上角的元素进行比较，比它大则可以去掉该行，小则可以去掉该列

总结：尽量让子问题的个数变少。
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = array.size();
        if(n == 0) return false;
        int m = array[0].size();
        if(m == 0) return false;
        int y = m - 1, x = 0;
        while(y >= 0 && y < m && x >= 0 && x < n) {
            if(target == array[x][y]) return true;
            else if(target > array[x][y]) x++;
            else y--;
        }
        return false;
    }
};