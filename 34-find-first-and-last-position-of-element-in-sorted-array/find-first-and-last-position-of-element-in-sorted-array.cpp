class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    
    // 1. First Position dhoondne ke liye
    int left = 0, right = nums.size() - 1;int mid;
    while (left <= right) {
        int mid = (left + right) / 2; // Overflow se bachne ke liye better way
        mid=(left+right)/2;
        if(nums[mid]>target){
            right=mid-1;
        }
        else if(nums[mid]==target){
            right=mid-1;
            result[0]=mid;
        }
        else{
            left=mid+1;
        }
    }
    //second position
    left = 0;right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2; // Overflow se bachne ke liye better way
        mid=(left+right)/2;
        if(nums[mid]>target){
            right=mid-1;
        }
        else if(nums[mid]==target){
            left=mid+1;
            result[1]=mid;
        }
        else{
            left=mid+1;
        }
    }
    return result;
}
};