class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int maxi=INT_MIN;int ans;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int> hash(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<=maxi;i++){
            if(hash[i]>1){
                ans=i;
            }
        }
        return ans;
    }
};