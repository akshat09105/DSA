class Solution {
public:
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
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        return max(f(nums,dp,nums.size()-1,1),f(nums,dp2,nums.size()-2,0));
        
    }
};