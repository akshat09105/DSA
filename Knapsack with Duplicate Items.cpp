class Solution {
  public:
    //memoization
    int f(int index,int w, vector<int>& wt, vector<int>& val,vector<vector<int>>&dp){
        if(index==0){
            return (w/wt[0])*val[0];
        }
        if(dp[index][w]!=-1)return dp[index][w];
        int not_take=0+f(index-1,w,wt,val,dp);
        int take=INT_MIN;
        if(wt[index]<=w){
            take=val[index]+f(index,w-wt[index],wt,val,dp);
        }
        return dp[index][w]=max(not_take,take);
    }
    int knappSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return f(n-1,capacity,wt,val,dp);
    }
    //tabulation
    int knapSackk(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int w=0;w<=capacity;w++){
            dp[0][w]=(w/wt[0])*val[0];
        }
        for(int index=1;index<n;index++){
            for(int w=0;w<=capacity;w++){
                int not_take=0+dp[index-1][w];
                int take=INT_MIN;
                if(wt[index]<=w){
                    take=val[index]+dp[index][w-wt[index]];
                }
                dp[index][w]=max(not_take,take);
            }
        }
        return dp[n-1][capacity];
    }
    //2 row space optimization
    int knapSacck(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<int>prev(capacity+1,0);
        for(int w=0;w<=capacity;w++){
            prev[w]=(w/wt[0])*val[0];
        }
        for(int index=1;index<n;index++){
            vector<int>curr(capacity+1,0);
            for(int w=0;w<=capacity;w++){
                int not_take=0+prev[w];
                int take=INT_MIN;
                if(wt[index]<=w){
                    take=val[index]+curr[w-wt[index]];
                }
                curr[w]=max(not_take,take);
            }
            prev=curr;
        }
        return prev[capacity];
    }
    //1 row space optimization
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=wt.size();
        vector<int>prev(capacity+1,0);
        for(int w=0;w<=capacity;w++){
            prev[w]=(w/wt[0])*val[0];
        }
        for(int index=1;index<n;index++){
            
            for(int w=0;w<=capacity;w++){
                int not_take=0+prev[w];
                int take=INT_MIN;
                if(wt[index]<=w){
                    take=val[index]+prev[w-wt[index]];
                }
                prev[w]=max(not_take,take);
            }
            
        }
        return prev[capacity];
    }
};
