class Solution {
public:
    int f(vector<int>& prices,int index,int n,int buy,int fee,vector<vector<int>>&dp){
        if(index==n){
            return 0;
        }
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        if(buy){
            profit=max(-prices[index]+f(prices,index+1,n,0,fee,dp),0+f(prices,index+1,n,1,fee,dp));
        }
        else{
            profit=max(prices[index]-fee+f(prices,index+1,n,1,fee,dp),0+0+f(prices,index+1,n,0,fee,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        //not multiple transaction fees classis dp on stocks problem where need to choose we have to particular transaction or not
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,n,1,fee,dp);
    }
};