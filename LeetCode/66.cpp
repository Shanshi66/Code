class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(len == 0) digits.push_back(1);
        else if(digits[len - 1] != 9) digits[len - 1] += 1;
        else {
            int tmp = len - 1;
            while(digits[tmp] == 9 && tmp >= 0) digits[tmp--] = 0;
            if(tmp >= 0) digits[tmp] += 1;
            else digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};