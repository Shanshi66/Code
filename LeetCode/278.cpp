// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m, ans;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(isBadVersion(m)){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }
        return ans;
    }
};