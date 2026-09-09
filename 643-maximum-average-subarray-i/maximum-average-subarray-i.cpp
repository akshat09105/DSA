class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    //subarray 2 pointers/sliding window is clicked
    int i=0;int sum=0;double avg=INT_MIN;
    for(int j=0;j<nums.size();j++){
        sum+=nums[j];
        if((j-i+1)==k){
            avg=max(avg,(double)sum/k);
            sum-=nums[i];
            i++;
        }
    }
    return avg;
    }
};