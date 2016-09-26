class Solution {
public:
    char getSymbol(int x){
        if(x < 10) return '0' + x;
        else return 'a' + x - 10;
    }
    string toHex(int num) {
        if(num == 0) return "0";
        int i = 0, mask = 15;
        string ans;
        while(num != 0 && i < 8){
            ans += getSymbol(num & mask);
            num >>= 4;
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};