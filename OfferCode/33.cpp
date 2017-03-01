/*
题目：把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

思路：用一个数组保留生成的丑数，保证按顺序生成。

记录上一次乘上因子后大于当前最大丑数的坐标，下一次不用重新开始。

*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if(index == 0) return 0;
        if(index == 1) return 1;
        vector<int> ugly_numbers;
        ugly_numbers.push_back(1);
        int t2 = 0, t3 = 0, t5 = 0, count = 1;
        while(count < index) {
            int m1, m2, m3;
            int _min = min(min(ugly_numbers[t2] * 2, ugly_numbers[t3] * 3), ugly_numbers[t5] * 5);
            ugly_numbers.push_back(_min);
            count++;
            while(ugly_numbers[t2] * 2 <= ugly_numbers[count - 1]) t2++;
            while(ugly_numbers[t3] * 3 <= ugly_numbers[count - 1]) t3++;
            while(ugly_numbers[t5] * 5 <= ugly_numbers[count - 1]) t5++;
        }
        return ugly_numbers[count - 1];
    }
};