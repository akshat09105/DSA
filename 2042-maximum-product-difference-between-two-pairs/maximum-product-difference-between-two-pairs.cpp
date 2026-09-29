class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1=nums[0];int max2=INT_MIN;int min1=nums[0];int min2=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>max1){
               max2=max1;
               max1=nums[i];
            }
            else{
                if(nums[i]>max2){
                    max2=nums[i];
                }
            }
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else{
                if(nums[i]<min2){
                    min2=nums[i];
                }
            }
        }
        return max1*max2-min1*min2;
    }
};