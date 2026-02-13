class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=prices[0];int max_profit=INT_MIN,profit;
        for(int i=0;i<prices.size();i++){
            profit=prices[i]-min_price;
            min_price=min(min_price,prices[i]);
            max_profit=max(max_profit,profit);

        }
        return max_profit;
    }
};