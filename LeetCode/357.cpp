class Solution {
public:
    int cal(int x){
        int prod = 1;
        for(int i = 10-x+1; i <= 9; i++)prod *= i;
        return prod;
    }
    //f[n] = f[n-1] + 9*C(9, n-1)*(n-1)!
    //考虑第一位取0~9
    int countNumbersWithUniqueDigits(int n) {
        if(n > 10) n = 10;
        int f = 1;
        for(int i = 1; i <= n; i++){
            f = f + 9 * cal(i);
        }
        return f;
    }
};