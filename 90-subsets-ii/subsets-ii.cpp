class Solution {
public:
    void SubsetswithoutDup(vector<int>&nums,int n,int index,vector<vector<int>>&ans,vector<int>&ds){
        
        ans.push_back(ds);
        for(int i=index;i<n;i++){
            if(i>index&&nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            SubsetswithoutDup(nums,n,i+1,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        SubsetswithoutDup(nums,n,0,ans,ds);
        return ans;
        
    }
};