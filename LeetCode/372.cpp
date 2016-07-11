class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int size_b = b.size(), t = a, ans = 1;
        const int MOD = 1337;
        for(int i = size_b - 1; i >= 0; i--){
            for(int j = 0; j < b[i]; j++){
                ans = (ans * (t % MOD)) % MOD;
            }
            int tmp = 1;
            for(int j = 0; j < 10; j++){
                tmp = (tmp * (t % MOD)) % MOD;
            }
            t = tmp;
        }
        return ans;
    }
};