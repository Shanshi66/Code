class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        while(n > 0){
            if(n & 1) break;
            n = n >> 1;
        }
        if(n == 1) return true;
        else return false;
    }
};

class Solution {
public:
    //只有一位1，减1之后，这个1变为0，后面所有位变为1
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        return !(n & (n - 1));
    }
};