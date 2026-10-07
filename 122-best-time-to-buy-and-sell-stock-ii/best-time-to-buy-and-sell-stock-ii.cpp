class Solution {
public:
//f(ind,buy) represents iss index ke buy ya sell tk mera maximum profit kitna hoga
    int f(vector<int>&prices,int index,bool buy,int n,vector<vector<int>>&dp){
        if(index==n){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy){//buy=1 means biy the stock
            profit=max(-prices[index]+f(prices,index+1,0,n,dp),0+f(prices,index+1,1,n,dp));
        }
        else{
            profit=max(prices[index]+f(prices,index+1,1,n,dp),0+f(prices,index+1,0,n,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,1,n,dp);
    }
};