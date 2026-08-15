class Solution {
public:
    int fn(vector<int>&nums,int k){
        set<int>st;
        int l=0;int r=0;int ans=0;unordered_map<int,int>mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            ans+=(r-l+1);
            r++; 
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //return no of good subarrays therefore kth - (k-1)th concept will be used
        return fn(nums,k)-fn(nums,k-1);
    }
};