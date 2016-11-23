/*
作差后寻找长度大于等于２的连续串，对于长度为ｋ的相等串的划分方法有：C(k, 2) - ｋ种
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        vector<int> diff;
        for(int i = 0; i < n - 1; i++){
            diff.push_back(A[i] - A[i + 1]);
        }
        n = n - 1;
        int start = 0, end = 0, ans = 0;
        while(start <= end && start < n){
            if(end < n && diff[end] == diff[start]){
                end++;
            }else{
                int length = end - start;
                if(length >= 2){
                    ans += (length + 1) * length / 2 - length;
                }
                start = end;
            }
        }
        return ans;
    }
};

/*
discuss中做法：
寻找长度为三的Arithmetic串，每个这样的串都可以和以前连续出现的数字组合，有++count种组合方法
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int count = 0, int ret = 0;
        for(int i = 1; i < A.size() - 1; i++)
        {
            if(A[i] - A[i-1] == A[i+1] - A[i]) ret += ++count;
            else count = 0;
        }
        return ret;
    }
};
