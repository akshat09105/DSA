class Solution {
public:
    int fn(vector<int>&nums,int k){
        int l=0;int r=0;int count=0;int ans=0;
        while(r<nums.size()){
            if(nums[r]%2!=0)count++;
            while(count>k){
                if(nums[l]%2!=0)count--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //count no of subarray....thereforce for k - (k-1) is clicked
        return fn(nums,k)-fn(nums,k-1);
    }
};