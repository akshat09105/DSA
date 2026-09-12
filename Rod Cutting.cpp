class Solution {
  public:
    //memoization
    int f(int index,int target,vector<int> &price,vector<vector<int>>&dp){
        if(index==0){
            return target*price[0];
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int not_take=0+f(index-1,target,price,dp);
        int take=INT_MIN;
        int length_cut=index+1;
        if(length_cut<=target){
            take=price[index]+f(index,target-length_cut,price,dp);
        }
        return dp[index][target]=max(take,not_take);
    }
    int cutrod(vector<int> &price) {
        // code here
        vector<vector<int>>dp(price.size(),vector<int>(price.size()+1,-1));
        return f(price.size()-1,price.size(),price,dp);
    }
    //tabulation
    int cutRoD(vector<int> &price) {
        // code here
        vector<vector<int>>dp(price.size(),vector<int>(price.size()+1,0));
        int n=price.size();
        int target=price.size();
        for(int i=0;i<=target;i++){
            dp[0][i]=i*price[0];
        }
        for(int index=1;index<n;index++){
            for(int t=0;t<=target;t++){
                int not_take=0+dp[index-1][t];
                int take=INT_MIN;
                int length_cut=index+1;
                if(length_cut<=t){
                    take=price[index]+dp[index][t-length_cut];
                }
                dp[index][t]=max(take,not_take);
            }
        }
        return dp[n-1][target];
    }
    //2D space optimization
    int cutRod(vector<int> &price) {
        // code here
        vector<int>prev(price.size()+1,0);
        int n=price.size();
        int target=price.size();
        for(int i=0;i<=target;i++){
            prev[i]=i*price[0];
        }
        for(int index=1;index<n;index++){
            vector<int>curr(n+1,0);
            for(int t=0;t<=target;t++){
                int not_take=0+prev[t];
                int take=INT_MIN;
                int length_cut=index+1;
                if(length_cut<=t){
                    take=price[index]+curr[t-length_cut];
                }
                curr[t]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[target];
    }
    //1D spaced optimization
    int cutROd(vector<int> &price) {
        // code here
        vector<int>prev(price.size()+1,0);
        int n=price.size();
        int target=price.size();
        for(int i=0;i<=target;i++){
            prev[i]=i*price[0];
        }
        for(int index=1;index<n;index++){
            for(int t=0;t<=target;t++){
                int not_take=0+prev[t];
                int take=INT_MIN;
                int length_cut=index+1;
                if(length_cut<=t){
                    take=price[index]+prev[t-length_cut];
                }
                prev[t]=max(take,not_take);
            }
        }
        return prev[target];
    }
};
