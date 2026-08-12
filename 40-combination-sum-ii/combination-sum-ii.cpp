class Solution {
public:
    void combination(vector<int>&ds,vector<vector<int>>&ans,int n,int target,int index,vector<int>candidates){
        if(target==0){
            ans.push_back(ds);            
        }
            
        
        for(int i=index;i<candidates.size();i++){
            if(i>index&&candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target)break;
            ds.push_back(candidates[i]);
            combination(ds,ans,n,target-candidates[i],i+1,candidates);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        combination(ds,ans,n,target,0,candidates);
        return ans;
    }
};