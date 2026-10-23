class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //Only DAG first doing it by BFS then by dfs
        //bfs
        //for Dag topo is equal to V if not its less than V which we also use in to detect DCG
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>inedges(V,0);
        for(int i=0;i<edges.size();i++){
            inedges[edges[i][1]]++;
        }
        //inedges is ready
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inedges[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                inedges[it]--;
                if(inedges[it]==0){
                    q.push(it);
                }
            }
        }
        return ans;
    }
};
