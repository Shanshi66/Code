class Solution {
public:
    bool isPowerOfThree(int n) {
        double x = log(n)/log(3);
        const double eps = 1e-11;
        //精度1, 0.99
        if(abs(x - floor(x)) < eps || abs(x - floor(x)) >= 1 - eps) return true;
        else return false;
    }
};