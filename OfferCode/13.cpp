/*
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

注意： 要保持相对顺序位置不变
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        if(size == 0) return;
        int last_odd_index = -1;
        for(int i = 0; i < size; i++) {
            if(isOdd(array[i])) {
                last_odd_index ++;
                if(last_odd_index != i) {
                    int tmp = array[i];
                    for(int j = i - 1; j >= last_odd_index; j--) {
                        array[j + 1] = array[j];
                    }
                    array[last_odd_index] = tmp;
                }
            }
        }
    }
    
    bool isOdd(int x) {
        if(x & 1) return true;
        else return false;
    }
};