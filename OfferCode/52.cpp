/*
题目：请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

/*
注意：很多细节，要想清楚再写
*/

class Solution {
public:
    bool match(char* str, char* pattern) {
        if(pattern == NULL || str == NULL) return false;
        int lenStr = strlen(str), lenPattern = strlen(pattern);
        if(lenPattern == 0 && lenStr == 0) return true;
        if(lenPattern == 0 && lenStr > 0) return false;
        
        int i = 0, j = 0;
        bool success = false;
        
        if(lenStr == 0) {
        	while(j + 1 < lenPattern && pattern[j + 1] == '*' ) j += 2;
            if(j >= lenPattern) return true;
            else return false;
        }
        if(str[i] == pattern[j] || pattern[j] == '.') {
            if(j + 1 < lenPattern && pattern[j + 1] == '*') {
                success = match(str + 1, pattern) || match(str + 1, pattern + 2);
            } else {
                success = match(str + 1, pattern + 1);
            }
        }
        if(j + 1 < lenPattern && pattern[j + 1] == '*') {
            success = success || match(str, pattern + 2);
        }
    	return success;
    }
};