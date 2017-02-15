/*
题目：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int f1 = 1, f2 = 1;
        for(int i = 3; i <= n; i++) {
            int tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
        }
        return f2;
    }
};

/*
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/

class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2) return number;
        int f1 = 1, f2 = 2;
        for(int i = 3; i <= number; i++) {
            int tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
        }
        return f2;
    }
};

/*
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

思路：利用错位相减推出公式
*/

class Solution {
public:
    int jumpFloorII(int number) {
        if(number <= 1) return 1;
        int prod = 1;
        for(int i = 2; i <= number; i++){
            prod <<= 1;
        }
        return prod;
    }
};

/*
题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
    int rectCover(int number) {
		if(number <=2 ) return number;
        int f1 = 1, f2 = 2;
        for(int i = 3; i <= number; i++) {
            int tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
        }
        return f2;
    }
};
