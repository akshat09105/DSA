class Solution {
public:
    void Combinations(vector<int>candidates,vector<vector<int>>&ans,vector<int>ds,int target,int index,int n){
        if(index==n||target<=0){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            Combinations(candidates,ans,ds,target-candidates[index],index,n);
            ds.pop_back();
        }
        Combinations(candidates,ans,ds,target,index+1,n);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        Combinations(candidates,ans,ds,target,0,n);
        return ans;
    }
};