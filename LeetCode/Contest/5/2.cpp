class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for(int i = 0; i <= num; i++){
            if(i > 4 || num - i > 6) continue;
            else search(ans, i, num - i);
        }
        return ans;
    }
    void search(vector<string> &ans, int up, int down){
        vector<int> hour, minutes;
        int m[6] = {32, 16, 8, 4, 2, 1};
        dfs(0, hour, up, m, 2, 6);
        dfs(0, minutes, down, m, 0, 6);
        for(auto h : hour){
            if(h >= 12) continue;
            for(auto m : minutes){
                if(m >= 60) continue;
                ans.push_back(transform(h, false) + string(":") + transform(m, true));
            }
        }
    }

    string transform(int t, bool flag){
        string time_str;
        if(t == 0) time_str = "0";
        else {
            while(t){
                time_str += '0' + t % 10;
                t /= 10;
            }
            reverse(time_str.begin(), time_str.end());
        }
        if(flag && time_str.length() < 2) time_str = string("0") + time_str;
        return time_str;
    }

    void dfs(int sum, vector<int> &arr, int num, int m[6], int cur, int end){
        if(cur <= end && num == 0){
            arr.push_back(sum);
            return;
        }
        if(cur >= end){
            return;
        }
        dfs(sum + m[cur], arr, num - 1, m, cur + 1, end);
        dfs(sum, arr, num, m, cur + 1, end);
    }
    
};