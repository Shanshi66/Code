class Solution {
public:
    int integerBreak(int n) {
        int max_prod = INT_MIN;
        if(n < 2) return 1;
        for(int i = 1; i < n; i++){
            int left = n % i, num = n / i;
            if(left == 0){
                max_prod = max(max_prod, (int)pow(i, num));
            }else{
                if(left * i  < left + i && num - 1 >= 2)
                    max_prod = max(max_prod, (left + i) * (int)pow(i, num - 1));
                else
                    max_prod = max(max_prod, left * (int)pow(i, num));
            }
        }
        return max_prod;
    }
};