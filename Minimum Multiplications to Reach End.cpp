class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>dist(1000,1e9);
        dist[start]=0;
        while(!q.empty()){
            auto iter=q.front();
            int node=iter.second;
            int steps=iter.first;
            q.pop();
            if(node==end)return steps;
            for(auto it:arr){
                int adjNode=(node*it)%1000;
                
                if(steps+1<dist[adjNode]){
                    dist[adjNode]=steps+1;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        return -1;
    }
};
