class Solution {
public:
    int f(int index,int target,vector<int>& coins,vector<vector<int>>&dp){
        if(index==0){
            if(target%coins[0]==0){
                return 1;
            }
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int not_take=f(index-1,target,coins,dp);
        int take=0;
        if(coins[index]<=target){
            take=f(index,target-coins[index],coins,dp);
        }
        return dp[index][target]=take+not_take;
    }
    int changee(int amount, vector<int>& coins) {
        //greedy cannot be applied because we can't see the future as we as we also need to find the best answer
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
    int change(int amount, vector<int>& coins){
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,0));
        for(int target=0;target<=amount;target++){
            dp[0][target]=(target%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            dp[i][0]=1;
        }
        for(int index=1;index<n;index++){
            for(int target=1;target<=amount;target++){
                int not_take=dp[index-1][target];
                int take=0;
                if(coins[index]<=target){
                    take=dp[index][target-coins[index]];
                }
                dp[index][target]=(long long)take+not_take;
            }
        }
        return dp[n-1][amount];
    }
};