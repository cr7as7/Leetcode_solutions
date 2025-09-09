class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;  // Pointer to potential buying day
        int sell = 1; // Pointer to potential selling day
        int maxProfit = 0;

        while (sell < prices.size()) {
            if (prices[sell] > prices[buy]) {
                // Profit is possible
                maxProfit = max(maxProfit, prices[sell] - prices[buy]);
            } else {
                // Found a cheaper price to buy
                buy = sell;
            }
            sell++;
        }

        return maxProfit;
    }
};