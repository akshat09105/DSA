class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int right=n-1;
        int left=0;
        int mid=0;
        int ans=nums.size();
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>=target){
                ans=mid;
                right=mid-1;
            }
        }
    return ans;
    }
};