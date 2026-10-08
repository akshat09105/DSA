class Solution {
public:
    //Memoization
    int f(vector<int>&prices,bool buy,int index,int n,int cap,vector<vector<vector<int>>>&dp){
        if(index==n||cap==0){
            return 0;
        }
        if(dp[index][buy][cap]!=-1)return dp[index][buy][cap];
        int profit=0;
        if(buy){//buy=1 means you have to buy
            profit=max(-prices[index]+f(prices,0,index+1,n,cap,dp),0+f(prices,1,index+1,n,cap,dp));
        }
        else{
            profit=max(prices[index]+f(prices,1,index+1,n,cap-1,dp),0+f(prices,0,index+1,n,cap,dp));
        }
        return dp[index][buy][cap]=profit;
    }
    int maxProfitt(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        
        return f(prices,1,0,n,2,dp);
    }
    //Tabulation 1)base 2)for loop 3)copy
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        for(int i=0;i<=1;i++){
            for(int j=0;j<=2;j++){
                dp[n][i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int buy=0;buy<=1;buy++){
                dp[i][buy][0]=0;
            }
        }
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit;
                    if(buy){//buy=1 means you have to buy
                    profit=max(-prices[index]+dp[index+1][0][cap],0+dp[index+1][1][cap]);
                    }
                    else{
                        profit=max(prices[index]+dp[index+1][1][cap-1],0+dp[index+1][0][cap]);
                    }
                    dp[index][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};