class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int arr_size = nums.size(), max=0;
        vector<int> ans;
        int dp[arr_size], pre[arr_size];
        if(arr_size == 0)return ans;
        for(int i = 0; i < arr_size; i++)dp[i]=pre[i]=0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < arr_size; i++){
            int j = i-1;
            for(; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] +1;
                        pre[i] = j;
                    }
                }
            }
            if(j < 0)dp[i] = 1, pre[i] = -1;
            if(dp[i] > max)max = i;
        }
        while(max!=-1){
            ans.push_back(nums[max]);
            max = pre[max];
        }
        return ans;
    }
};