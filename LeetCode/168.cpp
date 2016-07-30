class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while(n > 0){
            int left = n % 26;
            if(left == 0) left += 26, n -= 26;
            ans += 'A' + left - 1;
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};