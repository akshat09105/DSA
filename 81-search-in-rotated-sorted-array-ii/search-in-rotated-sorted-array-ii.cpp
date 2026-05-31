class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0;int right=nums.size()-1;int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]==target){
                //checking nums[mid]==target
                return true;
            }
            if(nums[left]==nums[mid] && nums[mid]==nums[right]){
                left++;right--;//we will shrink the array
                continue;
            }
            if(nums[mid]>=nums[left]){//left part is sorted 
            //therefore we can easily check that element belongs to left part or not
                if(target>=nums[left] && target<nums[mid]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{//right is sorted
            //we will check that element belongs to right part
                if(nums[mid]<target && target<=nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return false;
        
    }
};