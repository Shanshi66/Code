class Solution {
public:
    int titleToNumber(string s) {
        int base = 1, sum = 0;
        for(string::reverse_iterator iter = s.rbegin(); iter != s.rend(); iter++){
            sum += (*iter - 'A' + 1) * base;
            base *= 26;
        }
        return sum;
    }
};