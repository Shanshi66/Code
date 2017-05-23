/*
题目：写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

// 思路一： 模拟按位加

class Solution {
public:
    int Add(int num1, int num2){
		int base = 1, jin = 0, ans = 0;
        for(int i = 0; i < 32; i++) {
            if((num1 & base) && (num2 & base)) {
                if(jin == 1) ans |= base;
                jin = 1;
            } else if (!(num1 & base) && !(num2 & base)) {
                if(jin == 1) ans |= base;
                jin = 0; // 注意
            } else {
                if(jin == 0) ans |= base;
                else jin = 1;
            }
            base <<= 1;
        }
        return ans;
    }
};

/*
剑指offer做法：先求出不进位的结果，再加上进位。如果有进位，将进位左移再相加相当于加上进位。
*/

class Solution {
public:
    int Add(int num1, int num2){
		while(num2 != 0) {
            int sum = num1 ^ num2;
            int carry = (num1 & num2) << 1;
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};