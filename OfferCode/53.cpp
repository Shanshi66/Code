/*
题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

思路：
先定义出匹配式：[sign]digits[.[digits]][e|E[sign]digits]
*/

class Solution {
public:
    bool isNumeric(char* string) {
        if(string == NULL) return false;
        if(strlen(string) == 0) return false;
        int i = 0;
        if(string[i] == '+' || string[i] == '-') i++;
        while(string[i] >= '0' && string[i] <= '9') i++;
        if(string[i] == '.') {
            i++;
            while(string[i] >= '0' && string[i] <= '9') i++;
        }
        bool hasExp = true;
        if(string[i] == 'e' || string[i] == 'E'){
            i++;
            if(string[i] == '+' || string[i] == '-') i++;
            hasExp = false;
            while(string[i] >= '0' && string[i] <= '9') {
                i++;
            	hasExp = true;
            }
        }
        if(string[i] != '\0' || !hasExp) return false;
        else return true;
    }

};