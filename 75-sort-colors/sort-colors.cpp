class Solution {
public:
    void sortColors(vector<int>& nums) {
        //applying dutch national flag ALGO
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            //nums[mid]=0/1/2
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};