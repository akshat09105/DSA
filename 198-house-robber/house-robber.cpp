class Solution {
public:
    //tabulation
    int f(vector<int>&nums,int index,vector<int>&dp){
        if(index==0)return nums[0];
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        int pick=nums[index]+f(nums,index-2,dp);
        int notPick=f(nums,index-1,dp);
        return dp[index]=max(pick,notPick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)pick+=dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];

    }
};