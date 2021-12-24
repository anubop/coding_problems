class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;
        int min = INT_MAX;
        int profit;
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min) {
                min = prices[i];
            } else {
                profit = prices[i] - min;
                if(profit > maxProfit) {
                    maxProfit = profit;
                }
            }
        }
        return maxProfit;
    }
};