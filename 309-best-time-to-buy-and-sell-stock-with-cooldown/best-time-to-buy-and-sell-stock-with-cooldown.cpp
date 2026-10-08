class Solution {
public:
    //Memoization
    int f(vector<int>&prices,int index,int n,bool buy,bool cool,vector<vector<vector<int>>>&dp){
        if(index==n)return 0;
        //exploring all paths
        if(dp[index][buy][cool]!=-1)return dp[index][buy][cool];
        int profit;
        if(cool==1){//cool==1 means you can start
            
            if(buy){//buy==1 means buy krna hai
                profit=max(-prices[index]+f(prices,index+1,n,0,1,dp),0+f(prices,index+1,n,1,1,dp));
            }
            else{
                profit=max(prices[index]+f(prices,index+1,n,1,0,dp),0+f(prices,index+1,n,0,1,dp));
            }
        }
        else{
            return dp[index][buy][cool]=f(prices,index+1,n,1,1,dp);
        }
        return dp[index][buy][cool]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        /*dp[ind][buy][cool] or f(ind,buy,cool)->iss particular index par buy ya sell hone par with
         particular cool hai ki nhi par waha tk maximum profit kitna hoga*/ 
        return f(prices,0,n,1,1,dp);
    }
};