class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int right=n-1;
        int left=0;
        int mid=0;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]==target){
                return mid;
            }
            else{
                right=mid-1;
            }
        }
        if(nums[mid]>target){
            return mid;
        }
        else{
            return mid+1;
        }

    }
};