class Solution {
public:
    //Memoization
    int f(int index,vector<int>&nums,int target,vector<vector<int>>&dp,int &offset){
        
        if(index==0){
            if(target-nums[index]==0&&target+nums[index]==0){
                return 2;
            }
            if(target-nums[index]==0||target+nums[index]==0){
                return 1;
            }
            return 0;
        }
        if(dp[index][target+offset]!=-1)return dp[index][target+offset];
        int left=f(index-1,nums,target-nums[index],dp,offset);
        
        int right=f(index-1,nums,target+nums[index],dp,offset);
        
        return dp[index][target+offset]=left+right;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int offset=sum+abs(target);
        vector<vector<int>>dp(nums.size(),vector<int>(2*offset+abs(target)+1,-1));
        return f(nums.size()-1,nums,target,dp,offset);
    }
};