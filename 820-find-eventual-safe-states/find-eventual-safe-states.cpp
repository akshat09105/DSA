class Solution {
public:
    bool dfs(int src,vector<vector<int>>& graph,
    vector<int>&vis,vector<int>&path,vector<int>&check){
        vis[src]=1;
        path[src]=1;
        for(auto it:graph[src]){
            if(!vis[it]){
                if(dfs(it,graph,vis,path,check))return true;
            }
            else if(path[it]){
                return true;
            }
        }
        check[src]=1;
        path[src]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>path(n,0);
        vector<int>check(n,0);//will check is a node safe state or not
        for(int i=0;i<n;i++){
            dfs(i,graph,vis,path,check);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};