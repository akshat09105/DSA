class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        map<int,int>mpp;mpp[0]=1;int i=0;int sum=0;int ans=0;
        while(i<nums.size()){
            sum+=nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                ans+=mpp[sum-k];
            }
            mpp[sum]++;
            i++;
        }
        return ans;
    }
};