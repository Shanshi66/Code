/*
题目：输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

class Solution {
public:
     int  NumberOf1(int n) {
         int mask = 1, one_count = 0;
         for(int i = 0; i < 32; i++) {
             if(mask & n) one_count += 1;
             mask <<= 1;
         }
         return one_count;
     }
};

/*
剑指offer代码，右移末尾补0，前面丢弃
*/

class Solution {
public:
     int  NumberOf1(int n) {
         int mask = 1, one_count = 0;
         while(mask) {
             if(mask & n) one_count += 1;
             mask <<= 1;
         }
         return one_count;
     }
};

/*剑指offer代码*/

class Solution {
public:
     int  NumberOf1(int n) {
         int one_count = 0;
         while(n) {
             one_count++;
             n = n & (n - 1);
         }
         return one_count;
     }
};