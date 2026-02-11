class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //sum can be very very high so taking long long for sum
        //applying kadane's algo
        int sum=0;int maxi;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
            
        }
        return maxi;
    }
};