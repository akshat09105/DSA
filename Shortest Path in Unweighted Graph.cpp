class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>dist(V,INT_MAX);
        queue<int>q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        return dist[dest];
    }
};
