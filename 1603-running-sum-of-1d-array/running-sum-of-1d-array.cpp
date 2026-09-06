class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //first approach in mind is to create temp array but we will try more optimal approach
        int prev=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=prev+nums[i];
            prev=nums[i];
        }
        return nums;
    }
};