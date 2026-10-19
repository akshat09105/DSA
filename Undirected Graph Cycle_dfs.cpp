class Solution {
  public:
    //using bfs
    bool bfs(int src,vector<int>&vis,vector<int>adj[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    //using dfs
    bool dfs(int src,int parent,vector<int>&vis,vector<int>adj[]){
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(it,src,vis,adj))return true;
            }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n=edges.size();
        vector<int>vis(V,0);
        vector<int>adj[V];
        for(int i=0;i<n;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        //handling no of components
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                if(dfs(i,-1,vis,adj))return true;
            }
            
        }
        return false;
    }
};
