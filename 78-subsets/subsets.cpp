class Solution {
public:
    void subset(vector<int>nums,vector<vector<int>>&ans,vector<int>&set,int index,int n){
        if(index>=n){
            ans.push_back(set);
            return;
        }
        set.push_back(nums[index]);
        subset(nums,ans,set,index+1,n);
        set.pop_back();
        subset(nums,ans,set,index+1,n);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;int n=nums.size();
        vector<int>set;
        subset(nums,ans,set,0,n);
        return ans;
    }
};