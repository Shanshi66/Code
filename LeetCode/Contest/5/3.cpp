class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k--) remove_one(num);
        int len = num.length(), i = 0;
        for(; i < len; i++){
            if(num[i] != '0') break;
        }
        num.erase(num.begin(), num.begin() + i);
        if(num == "") num = "0";
        return num;
    }
    void remove_one(string &num){
        int len = num.length(), i = 1;
        for(; i < len; i++){
            if(num[i - 1] > num[i]) break;
        }
        num.erase(num.begin() + i - 1, num.begin() + i);
    }
};