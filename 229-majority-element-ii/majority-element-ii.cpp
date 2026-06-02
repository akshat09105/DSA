class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;vector<int>ans;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int x=n/3;
        for(auto [first,second]:mpp){
            if(second>x){
                ans.push_back(first);
            }
        }
        return ans;
    }
};