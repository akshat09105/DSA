class Solution {
public:
    bool zero_check(vector<int>&nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        
        int count=0;
        while(!zero_check(nums)){
            int x=INT_MAX;
            count++;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                x=min(x,nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[i]=nums[i]-x;
            }
        }
        }
        return count;
    }
};