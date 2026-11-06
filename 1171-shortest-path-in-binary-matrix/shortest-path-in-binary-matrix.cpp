class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        int n=grid.size();int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));        
        dist[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;
            pq.pop();
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    int adjx=x+dx;int adjy=y+dy;
                    if(adjx>=0&&adjx<n&&adjy>=0&&adjy<m){
                        if(grid[adjx][adjy]==0&&dis+1<dist[adjx][adjy]){
                        
                            
                            pq.push({dis+1,{adjx,adjy}});
                            dist[adjx][adjy]=dis+1;
                        
                        }
                    }
                    
                }
            }
        }   
        if((dist[n-1][m-1]==1e9)){
            return -1;
        }
        return dist[n-1][m-1];
    }
};