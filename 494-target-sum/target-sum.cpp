class Solution {
public:
    int f(int index,int sum,vector<int>&arr,vector<vector<int>>&dp){
        if(index==0){
            if(sum==0&&arr[0]==0)return 2;
            if(sum==0||sum==arr[0])return 1;
            return 0;
        }
        if(dp[index][sum]!=-1)return dp[index][sum];
        int not_take=f(index-1,sum,arr,dp);
        int take=0;
        if(arr[index]<=sum)take=f(index-1,sum-arr[index],arr,dp);
        return dp[index][sum]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum-target<0)return 0;
        if((sum-target)%2!=0)return 0;
        int s2=(sum-target)/2;
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return f(n-1,s2,nums,dp);
    }
};