/*
题目：求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

*/

/*题意理解错了，以为是求包含1的数字的个数，数位DP*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	vector<int> digits;
        if(n < 1) return 0;
        while(n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int len = digits.size();
        vector<vector<int>> dp(10, vector<int>(len + 1, 0));
        for(int i = 1; i <= len; i++) {
            for(int j = 0; j < 10; j++) {
                if(j == 0) {
                    dp[j][i] += dp[9][i - 1];
                }
                else if(j == 1) dp[j][i] = dp[0][i] + pow(10, i - 1);
                else {
                    dp[j][i] += dp[j - 1][i] + dp[9][i - 1];
                }
            }
        }
        int res = 0, i;
        for(i = len - 1; i >= 0; i--) {
            if(digits[i] > 0) res += dp[digits[i] - 1][i + 1];
            if(digits[i] == 1) break;
        }
        int tmp = 0;
        for(--i; i >= 0; i--) {
            tmp *= 10;
            tmp += digits[i];
        }
        tmp += 1;
        res += tmp;
       	return res;
    }
};

/*正确题意的DP做法*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	vector<int> digits;
        if(n < 1) return 0;
        while(n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int len = digits.size();
        vector<vector<int>> dp(10, vector<int>(len + 1, 0));
        for(int i = 1; i <= len; i++) {
            for(int j = 0; j < 10; j++) {
                if(j == 0) {
                    dp[j][i] += dp[9][i - 1];
                }
                else if(j == 1) dp[j][i] = dp[0][i] + pow(10, i - 1) + dp[9][i - 1];
                else {
                    dp[j][i] += dp[j - 1][i] + dp[9][i - 1];
                }
            }
        }
        int res = 0, i;
        vector<int> num(len, 0);
        for(int i = 0; i < len; i++) {
            if(i == 0) num[i] = digits[i];
            else {
                num[i] = digits[i] * pow(10, i) + num[i - 1];
            }
        }
        for(i = len - 1; i >= 0; i--) {
            if(digits[i] == 0) continue;
            if(digits[i] == 1 && i > 0) res += num[i - 1] + 1;
            res += dp[digits[i] - 1][i + 1];
        }
        if(digits[0] == 1) res += 1;
       	return res;
    }
};