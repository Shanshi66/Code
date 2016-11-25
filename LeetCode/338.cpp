class Solution {
public:
    vector<int> countBits(int num){
        vector<int> count(num + 1, 0);
        for(int i = 1; i <= num; i++){
            count[i] = count[i & (i - 1)] + 1;
        }
        return count;
    }
};