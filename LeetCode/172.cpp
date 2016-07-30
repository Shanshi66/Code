class Solution {
public:
    int trailingZeroes(int n) {
         int count = 0;
         while(n){
             n /= 5;
             count += n;
         }
         return count;
    }
};