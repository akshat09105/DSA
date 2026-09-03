class Solution {
public:
    int f(vector<int>coins,int amount,int index,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[index]==0)return amount/coins[0];
            return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int notTake=0+f(coins,amount,index-1,dp);
        int take=1e9;
        if(coins[index]<=amount){
            take=1+f(coins,amount-coins[index],index,dp);
        }
        return dp[index][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins,amount,coins.size()-1,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};