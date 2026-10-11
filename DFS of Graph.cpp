class Solution {
  private:
    void DFS(int node,vector<int>&vis,vector<int>&ans,vector<vector<int>>& adj){
        vis[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(vis[it]!=1){
                DFS(it,vis,ans,adj);
            }
        }
        
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>ans;
        DFS(0,vis,ans,adj);
        return ans;
        
    }
};
