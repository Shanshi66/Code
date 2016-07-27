class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        if(days < 2) return 0;
        int min_price[days], max_price[days];
        for(int i = 0, _min = prices[0]; i < days; i++){
            if(prices[i] < _min) _min = prices[i];
            min_price[i] = _min;
        }
        for(int i = days - 1, _max = prices[i]; i >= 0; i--){
            if(prices[i] > _max) _max = prices[i];
            max_price[i] = _max;
        }
        int ans = 0;
        for(int i = 1; i < days; i++){
            ans = max(ans, max_price[i] - min_price[i - 1]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size(), min_price = INT_MAX, max_profit = 0;
        for(int i = 0; i < days; i++){
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};