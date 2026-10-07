class Solution {
public:
//memoization
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
    int maxprofit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,1,n,dp);
    }
    //tabulation
    int maxProfitt(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        for(int i=0;i<2;i++){
            dp[n][i]=0;
        }
        for(int index=n-1;index>=0;index--){
            for(int j=1;j>=0;j--){
                int profit=0;
                if(j){//buy=1 means biy the stock
                    profit=max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
                }
                else{
                    profit=max(prices[index]+dp[index+1][1],0+dp[index+1][0]);
                }
                dp[index][j]=profit;
            }
        }
        return dp[0][1];
    }
    //space optimal
    int maxPprofit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        for(int i=0;i<2;i++){
            prev[i]=0;
        }
        for(int index=n-1;index>=0;index--){
            for(int j=1;j>=0;j--){
                int profit=0;
                if(j){//buy=1 means biy the stock
                    profit=max(-prices[index]+prev[0],0+prev[1]);
                }
                else{
                    profit=max(prices[index]+prev[1],0+prev[0]);
                }
                curr[j]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
    //variable space optimize
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        
        int prev_buy=0,prevNot_buy=0;
        for(int index=n-1;index>=0;index--){
            int curr_buy=0,currNot_buy=0;
            int profit=0;
            curr_buy=max(-prices[index]+prevNot_buy,0+prev_buy);
            currNot_buy=max(prices[index]+prev_buy,0+prevNot_buy);                
            prev_buy=curr_buy;
            prevNot_buy=currNot_buy;
        }
        return prev_buy;
    }

};