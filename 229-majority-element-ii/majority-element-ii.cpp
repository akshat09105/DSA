class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();int x=n/3;;
        map<int,int>mpp;vector<int>ans;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>x){
                ans.push_back(nums[i]);
                mpp[nums[i]]=-5*(10^4);
            }
        }
        return ans;
    }
};