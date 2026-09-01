class Solution {
  public:
    int f(int index,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
        if(index==0){
            if(wt[index]<=W){
                return val[index];
            }
            return 0;
        }
        if(dp[index][W]!=-1)return dp[index][W];
        int Not_take=f(index-1,W,wt,val,dp);
        int take=INT_MIN;
        if(wt[index]<=W){
            take=val[index]+f(index-1,W-wt[index],wt,val,dp);
        }
        return dp[index][W]=max(Not_take,take);
        
    }
    int napsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return f(n-1,W,wt,val,dp);
    }
    //Tabulation
    int knappsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<=W;i++){
            dp[0][i]=val[0];
        }
        for(int index=1;index<n;index++){
            for(int w=0;w<=W;w++){
                int Not_take=dp[index-1][w];
                int take=INT_MIN;
                if(wt[index]<=w){
                    take=val[index]+dp[index-1][w-wt[index]];
                }
                dp[index][w]=max(Not_take,take);
            }
        }
        return dp[n-1][W];
    }
    //space-optimization
    int knapppsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<int>prev(W+1,0);
        for(int i=wt[0];i<=W;i++){
            prev[i]=val[0];
        }
        for(int index=1;index<n;index++){
            vector<int>curr(W+1,0);
            for(int w=0;w<=W;w++){
                int Not_take=prev[w];
                int take=INT_MIN;
                if(wt[index]<=w){
                    take=val[index]+prev[w-wt[index]];
                }
                curr[w]=max(Not_take,take);
            }
            prev=curr;
        }
        return prev[W];
    }
    //space-optimized-1d array
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<int>prev(W+1,0);
        for(int i=wt[0];i<=W;i++){
            prev[i]=val[0];
        }
        for(int index=1;index<n;index++){
            vector<int>curr(W+1,0);
            for(int w=W;w>=wt[index];w--){
                int Not_take=prev[w];
                int take=INT_MIN;
                if(wt[index]<=w){
                    take=val[index]+prev[w-wt[index]];
                }
                prev[w]=max(Not_take,take);
            }
            
        }
        return prev[W];
    }
    
};
