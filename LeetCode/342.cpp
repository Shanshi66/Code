class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0) return false;
        if((num & (num - 1)) != 0) return false;
        while(num > 0){
            if(num == 1) return true;
            num >>= 2;
        }
        return false;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 0) return false;
        if(num & (num - 1)) return false;
        return num & 0x55555555;
    }
};