class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //src to dest dijkrta algo is clicking in mind
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]}); 
        }
        queue<pair<int,pair<int,int>>>q;//{stops,{node,cost}}
        vector<int>fair(n,1e9);
        fair[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k||node==dst)continue;
            for(auto iter:adj[node]){
                int adjNode=iter.first;
                int edW=iter.second;
                if(cost+edW<fair[adjNode]&&stop<=k){
                    fair[adjNode]=cost+edW;
                    q.push({stop+1,{adjNode,fair[adjNode]}});
                }
            }

        }
        if(fair[dst]==1e9)return -1;
        return fair[dst];
    }
};