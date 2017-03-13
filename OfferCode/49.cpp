/*
题目：将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0 

注意几种情况：
1. 字符串为空
2. 有非0~9字符
3. 正负号
4. 溢出

*/


class Solution {
public:
    int StrToInt(string str) {
        long long num = 0;
        const long long MAXINT = 0x000000007fffffff;
        int len = str.length();
        if(len > 0) {
            bool minus = false;
            int i = 0;
            if(str[i] == '-') {
                minus = true;
            	i++;
            }
            if(str[i] == '+') i++;
           	while(i < len) {
                if(str[i] >= '0' && str[i] <= '9') {
                    num = num * 10 + str[i] - '0';
                	if((minus && num > MAXINT + 1) || (!minus && num > MAXINT)) {
                        num = 0;
                        break;
                    }
                }
                else {
                    num = 0;
                    break;
                }
                i++;
            }
            if(minus == true) num = -num;
        }
        return num;
    }
};