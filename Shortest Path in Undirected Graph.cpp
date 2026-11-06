class Solution {
  public:
    using P= pair<int,int>;
    using state = pair<long long , vector<int>>;

    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
        vector<P> adj[V+1];

        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }


        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({0, {src}});

        vector<int> dist(V+1, 1e9);
        vector<vector<int>> path(V+1);

        dist[src]=0;
        path[src] = {src};

        while(!pq.empty()){
              auto it = pq.top();
              long long dis = it.first;
              vector<int> curpath = it.second;
              pq.pop();

              int u = curpath.back();


             if(dis>dist[u] || curpath> path[u]) continue;


            if(u==dest){
                return curpath;
            }


            for(auto it : adj[u]){
                  int v = it.first;
                  int wt = it.second;

                  vector<int> newpath = curpath;
                  newpath.push_back(v);

                  if(dis + wt < dist[v] || (dis+wt==dist[v] && newpath < path[v])){
                        dist[v] = dis+wt;
                        path[v] = newpath;
                        pq.push({dist[v], newpath});

                  }

            }
        }

        return {-1};

    }
};
