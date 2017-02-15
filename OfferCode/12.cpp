/*
题目：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

思路：采用分治，对exponent进行折半。
*/

class Solution {
public:
    double Power(double base, int exponent) {
    	if(exponent == 1) return base;
        if(exponent == 0) return 1;
        bool is_negative = false;
        if(exponent < 0) {
            is_negative = true;
            //if(equal(base, 0.0)) throw new std::exception('Invalid input');
            exponent = -exponent;
        }
        double ans;
        if(exponent & 1) {
            double half = Power(base, (exponent - 1) / 2);
            ans = base * half * half;
        } else {
            double half = Power(base, exponent / 2);
            ans = half * half;
        }
        if(is_negative) return 1 / ans;
        else return ans;
    }
};

/*
以上程序存在如下问题：
1. 当exponent为负，base等于0时，程序会崩溃，需添加注释的话
2. 浮点型比较时不能直接用等号，可能有误差。用一下函数较好。
*/

bool equal(double a, double b) {
    double eps = 1e-7;
    if(abs(a - b) < eps) return true;
    else return false;
}

/*
    快速幂解法
*/

class Solution {
public:
    double Power(double base, int exponent) {
    	bool is_negative = false;
        if(exponent < 0) {
            is_negative = true;
            exponent = -exponent;
        }
        double new_base = base, result = 1;
        while(exponent){
            if(exponent & 1) {
                result *= new_base;
            }
           	new_base *= new_base;
            exponent >>= 1;
        }
        if(is_negative) return 1 / result;
        else return result;
    }
};