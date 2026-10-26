class Solution {
public:
    void dfs(int src,int target,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans){
        if(src==target){
            path.push_back(src);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(src);
        for(auto it:graph[src]){
            dfs(it,target,graph,path,ans);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        vector<vector<int>>ans;
        int n=graph.size();
        dfs(0,n-1,graph,path,ans);
        return ans;
    }
};