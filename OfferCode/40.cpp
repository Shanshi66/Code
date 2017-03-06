/*
题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

思路：先将原数组异或求和，最后的和必定不为0，则必定有一位为1。按照这一位是否为1将数组分成两部分，则两个只出现一次的数将处在两个数组中。再分别异或。

*/


class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		if(data.size() < 2) return;
        int xorSum = 0;
        for(int i = 0; i < data.size(); i++) {
            xorSum ^= data[i];
        }
        int base = 1;
        while(base > 0){
           	if(xorSum & base) break;
            base <<= 1;
        }
        int xorSum1 = 0, xorSum2 = 0;
        for(int i = 0; i < data.size(); i++) {
            if(data[i] & base) xorSum1 ^= data[i];
            else xorSum2 ^= data[i];
        }
        *num1 = xorSum1;
        *num2 = xorSum2;
    }
};