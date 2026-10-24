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
    vector<int> eventualSafeNode(vector<vector<int>>& graph) {
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
    //solving it by topological sort (BFS) kahn's algo
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>RevGraph[n];
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                RevGraph[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:RevGraph[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};