class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int f1 = 1, f2 = 2, ans;
        for(int i = 3; i <= n; i++){
            ans = f1 + f2;
            f1 = f2;
            f2 = ans;
        }
        return ans;
    }
};