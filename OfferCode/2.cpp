/*
题目：请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

总结：从后往前替换可以减少重复移动
注意：最后一个字符并不是移动到最后，需要计算替换后字符串的长度。
*/


class Solution {
public:
    void replaceSpace(char *str,int length) {
        int origin_len = strlen(str);
        int space_count = 0;
        for(int i = 0; i < origin_len; i++) {
            if(str[i] == ' ') space_count += 1;
        }
        for(int i = origin_len; i < length; i++) {
            str[i] = '\0';
        }
        int p_origin = origin_len - 1, p_after = space_count * 2 + origin_len - 1;
        while(p_origin >= 0){
            if(str[p_origin] == ' '){
                str[p_after--] = '0';
                str[p_after--] = '2';
                str[p_after--] = '%';
            } else {
                str[p_after--] = str[p_origin];
            }
            p_origin--;
        }
    }
};