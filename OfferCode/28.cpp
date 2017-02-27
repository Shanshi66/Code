/*
题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

解法一：摩尔投票法，每次删除两个不同的元素，删除完后验证最后的元素。
为什么要验证：考虑1，3，1，4，1，5，2这个样例，最后剩下的是2，但2明显不是超过两次的元素。
*/


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        if(size == 0) return 0;
        int val, count = 0;
        for(int i = 0; i < size; i++) {
            if(count == 0) {
                val = numbers[i];
            	count++;
            }
            else {
                if(numbers[i] == val) count++;
            	else count--;
            }
        }
        count = 0;
        for(int i = 0; i < size; i++) {
            if(numbers[i] == val) count++;
        }
        if(count * 2 > size) return val;
        return 0;
    }
};

/*
解法二：利用快排的partition, 超过一半的数一定是中位数
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int size = numbers.size();
        if(size == 0) return 0;
        int mid = size >> 1;
        int start = 0, end = size - 1;
        int index = partition(numbers, start, end);
        while(index != mid) {
            if(index < mid) {
                start = index + 1;
            } else {
                end = index - 1;
            }
            index = partition(numbers, start, end);
        }
        int result = numbers[index], count = 0;
        for(int i = 0; i < size; i++) {
            if(numbers[i] == result) count++;
        }
        if(count * 2 > size) return result;
        return 0;
    }

    int partition(vector<int> &numbers, int start, int end){
        int small = start - 1;
        for(int i = start; i <= end; i++) {
            if(numbers[i] < numbers[end]){
                small++;
                if(i == small) continue;
                swap(numbers[small], numbers[i]);
            }
        }
        swap(numbers[end], numbers[++small]);
        return small;
    }
};