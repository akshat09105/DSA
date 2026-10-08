class Solution {
public:
    int f(vector<int>& prices,int index,int n,int total_transaction,int k,vector<vector<int>>&dp){
        if(index==n){//base case
            return 0;
        }
        if(total_transaction==2*k+1){
            return 0;
        }
        if(dp[index][total_transaction]!=-1)return dp[index][total_transaction];
        int profit;
        if(total_transaction%2==0){
            profit=max(-prices[index]+f(prices,index+1,n,total_transaction+1,k,dp),0+f(prices,index+1,n,total_transaction,k,dp));
        }
        else{
            profit=max(prices[index]+f(prices,index+1,n,total_transaction+1,k,dp),0+f(prices,index+1,n,total_transaction,k,dp));
        }
        return dp[index][total_transaction]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        return f(prices,0,n,0,k,dp);
    }
};