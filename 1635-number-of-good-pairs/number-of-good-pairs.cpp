class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int maxi=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int>hash(maxi+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<hash.size();i++){
            while(hash[i]>1){
                ans+=(hash[i]-1);
                hash[i]--;
            }
        }
        return ans;
    }
};