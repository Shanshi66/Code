class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i = 0; i < rowIndex + 1; i++){
            int mid = i % 2 ? i / 2 + 1 : i / 2;
            for(int j = 1; j < mid; j++){
                ans[j] = ans[i - j] + ans[i - j - 1];
            }
            if(i > 0 && i % 2 == 0) ans[i / 2] = 2 * ans[i / 2], mid++;
            for(int j = mid; j < i; j++) ans[j] = ans[i - j];
            ans.push_back(1);
        }
        return ans;
    }
};