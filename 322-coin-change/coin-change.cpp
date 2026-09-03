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
    int coinchange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins,amount,coins.size()-1,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)dp[0][t]=t/coins[0];
            else dp[0][t]=1e9;
        }
        for(int index=1;index<n;index++){
            for(int t=0;t<=amount;t++){
                int notTake=0+dp[index-1][t];
                int take=1e9;
                if(coins[index]<=t){
                    take=1+dp[index][t-coins[index]];
                }
                dp[index][t]=min(take,notTake);  
            }
        }
        int ans=dp[n-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};