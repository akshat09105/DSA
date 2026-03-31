class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        
        int left=0;int right=n-1;int mid;
        
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                return nums[mid];
            }
            else if(nums[mid]==nums[mid+1]){
                if((mid+1)%2!=0){
                    left=mid+2;
                }
                else{
                    right=mid-1;
                }
            }
            else{
                if(mid%2!=0){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};