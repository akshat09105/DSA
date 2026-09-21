class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //brute
        int n=nums.size();
        vector<int>ans(n,-1);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int count=0;
            if(mpp.find(nums[i])!=mpp.end()){
                ans[i]=mpp[nums[i]];
                continue;
            }

            for(int j=0;j<n;j++){
                if(i!=j&&nums[i]>nums[j]){
                    count++;
                }
            }
            mpp[nums[i]]=count;
            ans[i]=count;
        }
        return ans;
    }
};