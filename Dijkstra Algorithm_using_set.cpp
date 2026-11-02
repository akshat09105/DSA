class Solution {
  public:
    vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
        // Code here
        int n=adj.size();
        vector<int>dist(n,1e9);
        set<pair<int,int>>st;
        dist[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase({dis,node});
            for(auto it:adj[node]){
                int adjNode=it[0];
                int weight=it[1];
                if(dis+weight<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dis+weight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
    }
};
