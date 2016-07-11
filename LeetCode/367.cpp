class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0, r = num;
        bool flag = false;
        while(l <= r){
            if(flag)break;
            long long m = (r - l) / 2 + l;
            if(m * m == num) flag = true;
            else if(m * m > num) l = m + 1;
            else r = m - 1;
        }
        return flag;
    }
};