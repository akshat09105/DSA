class Solution {
  public:
    int f(vector<int>& arr, int target,int index,vector<vector<int>>&dp){
        
        if(index==0){
            if(target==0&&arr[0]==0)return 2;
            if(arr[index]==target)return 1;
            if(target==0)return 1;
            else return 0;
        }
        if(dp[index][target]!=-1)return dp[index][target];
        int not_take=f(arr,target,index-1,dp);
        int take=0;
        if(arr[index]<=target){
            take=f(arr,target-arr[index],index-1,dp);
        }
        return dp[index][target]=take+not_take;
    }
    int perfecttSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(target+1,-1));
        return f(arr,target,arr.size()-1,dp);
    }
    //tabulation
    int perfectttSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(target+1,0));
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
            if(arr[0]<=target){
            dp[0][arr[0]]=1;
            }
        }
        for(int index=1;index<arr.size();index++){
            for(int t=0;t<=target;t++){
                int not_take=dp[index-1][t];
                int take=0;
                if(arr[index]<=t){
                    take=dp[index-1][t-arr[index]];
                }
                dp[index][t]=take+not_take;
            }
        }
        return dp[arr.size()-1][target];
    }
    //space optimal
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int>prev(target+1,0);
        if(arr[0]==0){
            prev[0]=2;
        }
        else{
            prev[0]=1;
            if(arr[0]<=target){
            prev[arr[0]]=1;
            }
        }
        for(int index=1;index<arr.size();index++){
            vector<int>curr(target+1,0);
            for(int t=0;t<=target;t++){
                int not_take=prev[t];
                int take=0;
                if(arr[index]<=t){
                    take=prev[t-arr[index]];
                }
                curr[t]=take+not_take;
            }
            prev=curr;
        }
        return prev[target];
    }
};
