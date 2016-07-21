class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len < 2)return len;
        //dp[i]表示以nums[i]结尾的最长wiggle sequence
        //O(n^2)
        int dp[len], ans = 1;
        bool flag[len];
        for(int i = 0; i < len; i++)dp[i] = 1;
        for(int i = 1; i < len; i++){
            int max_len = -1;
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] == nums[j]) continue;
                if(dp[j] == 1){
                    if(dp[j] > max_len){
                        max_len = dp[j];
                        flag[i] = (nums[i] > nums[j]);
                    }
                }else{
                    if((nums[i] > nums[j]) == !flag[j]){
                        if(dp[j] > max_len){
                            max_len = dp[j];
                            flag[i] = !flag[j];
                        }
                    }
                }
            }
            dp[i] = max_len + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


class Solution {
public:
    //贪心，看成一条折线段，取其端点
    int wiggleMaxLength(vector<int>& nums) {
        int size_nums = nums.size();
        if(size_nums < 2) return size_nums;
        int count = 1, flag = 0;
        for(int i = 1; i < size_nums; i++){
            if(nums[i] != nums[i - 1]){
                if(flag == 0) flag = (nums[i] > nums[i - 1]) ? 1 : -1;
                else if(flag == 1) {
                    if(nums[i] < nums[i - 1]) flag = -1, count++;
                }
                else {
                    if(nums[i] > nums[i - 1]) flag = 1, count++;
                }
            }
        }
        return count + 1;
    }   
};