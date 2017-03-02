/*
题目：在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置

然后并不是只有大写字母，也是坑
*/


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.length() == 0) return -1;
        int count[256], first_time[256];
        for(int i = 0; i < 256; i++) {
			count[i] = 0;
            first_time[i] = -1;
        }
        for(int i = 0; i < str.length(); i++) {
            int index = str[i];
            count[index] += 1;
            if(first_time[index] == -1) {
                first_time[index] = i;
            }
        }
        int res = 10000;
        for(int i = 0; i < 256; i++) {
            if(count[i] == 1) {
                res = min(res, first_time[i]);
            }
        }
        return res;
    }
};