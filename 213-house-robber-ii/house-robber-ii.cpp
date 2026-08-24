class Solution {
public:

    //tabulation
    int f(vector<int>&nums,vector<int>&ds,int index,int base){
        if(index==base)return nums[base];
        if(index<base)return 0;
        if(ds[index]!=-1)return ds[index];
        int pick=nums[index]+f(nums,ds,index-2,base);
        int notpick=f(nums,ds,index-1,base);
        return ds[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){
            int pick=nums[i];
            if(i>1)pick+=dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        int withoutLast=dp[n-2];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int pick=nums[i];
            if(i>2)pick+=dp[i-2];
            int notPick=dp[i-1];
            dp[i]=max(pick,notPick);
        }
        int withOutZero=dp[n-1];
        return max(withoutLast,withOutZero);
        
    }
};