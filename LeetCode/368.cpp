class Solution {
    /*
        DP, 将数组排序后将会产生无后效性，对于数i和j, i<j,如果j能被i整除，则j能被能整除i的数整出
    */
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int arr_size = nums.size(), max=0;
        vector<int> ans;
        int dp[arr_size], pre[arr_size];
        if(arr_size == 0)return ans;
        for(int i = 0; i < arr_size; i++)dp[i] = pre[i] = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < arr_size; i++){
            int j = i-1;
            bool flag = true;
            for(; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    flag = false;
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if(flag)dp[i] = 1, pre[i] = -1;
            if(dp[i] > max)max = i;
        }
        while(max!=-1){
            ans.push_back(nums[max]);
            max = pre[max];
        }
        return ans;
    }
};