class Solution {
public:
    int findNthDigit(int n) {
        long long base = 9, p = 1;
        while(n > base * p){
            n -= base * p;
            // cout << n << " " << base << " " << p << " " << endl;
            base *= 10;
            p++;
        }
        long long index = ceil(n * 1.0 / p), wei = n % p;
        if(wei == 0) wei += p;
        long long num = 1;
        for(int i = 1; i < p; i++){
            num *= 10;
        }
        num += index - 1;
        // cout << n << " " <<index << " " << wei << " " << num << " " << p << endl;
        wei = p - wei;
        while(wei > 0){
            num = num / 10;
            wei--;
        }
        return num % 10;
    }
};