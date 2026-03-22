class Solution {
public:
    int findPeakElement(vector<int>& nums) {
       int n=nums.size();
       if(nums.size()==1){
        return 0;
       }
       if(nums[0]>nums[1]){
        return 0;
       } 
       if(nums[n-1]>nums[n-2]){
        return n-1;
       }
       int low=1;int high=n-2;int mid;
       while(low<=high){
        mid=(low+high)/2;
        if(nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1]){
            return  mid;
        }
        else if(nums[mid]>nums[mid-1]){//peak is on right
            low=mid+1;
        }
        else if(nums[mid]>nums[mid+1]){//peak is on left
            high=mid-1;
        }
        else{
            high=mid-1;
        }

       }
       return -1;

    }
};