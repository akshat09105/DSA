class Solution {
public:
    //Memoization
    int f(vector<int>&prices,int index,int n,bool buy,vector<vector<int>>&dp){
        if(index>=n)return 0;
        //exploring all paths
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        
            
        if(buy){//buy==1 means buy krna hai
            profit=max(-prices[index]+f(prices,index+1,n,0,dp),0+f(prices,index+1,n,1,dp));
        }
        else{
            profit=max(prices[index]+f(prices,index+2,n,1,dp),0+f(prices,index+1,n,0,dp));
        }
        
        
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        /*dp[ind][buy][cool] or f(ind,buy,cool)->iss particular index par buy ya sell hone par with
         particular cool hai ki nhi par waha tk maximum profit kitna hoga*/ 
        return f(prices,0,n,1,dp);
    }
};