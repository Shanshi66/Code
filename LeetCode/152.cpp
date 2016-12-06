/*
记录以ｉ为结尾的最大正乘积和最小负乘积
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> max_positive_prod(n, -1);
        vector<int> min_negative_prod(n, 1);
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                max_positive_prod[i] = nums[i];
                min_negative_prod[i] = nums[i];
                continue;
            }
            max_positive_prod[i] = max(max(max_positive_prod[i - 1] * nums[i],                                                 min_negative_prod[i - 1] * nums[i]), nums[i]);
            min_negative_prod[i] = min(min(max_positive_prod[i - 1] * nums[i],                                                 min_negative_prod[i - 1] * nums[i]), nums[i]);
            // cout << max_positive_prod[i] << " " << min_negative_prod[i] << endl;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            ans = max(ans, max(max_positive_prod[i], min_negative_prod[i]));
        }
        return ans;
    }
};