class Solution {
public:
    int findKthNumber(int n, int k) {
        vector<int> digit;
        while(n){
            digit.push_back(n % 10);
            n = n / 10;
        }
        int size_digit = digit.size();
        
    }
};