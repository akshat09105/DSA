class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8&&dist[u]+wt<dist[v]){//if where will be -ve weight then dist[u]+wt<dist[v]
                                       //therefore we need to see its not 1e8                    
                    dist[v]=dist[u]+wt;
                }
            }
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
