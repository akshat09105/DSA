class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)return -1;
        if(grid.size()==1&&grid[0].size()==1)return 1;
        int n=grid.size();int m=grid[0].size();
        queue<pair<int,pair<int,int>>>pq;
        pq.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));        
        dist[0][0]=1;
        while(!pq.empty()){
            auto it=pq.front();
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;
            pq.pop();
            if(dist[x][y]<dis)continue;
            for(int dx=-1;dx<=1;dx++){
                for(int dy=-1;dy<=1;dy++){
                    int adjx=x+dx;int adjy=y+dy;
                    if(adjx>=0&&adjx<n&&adjy>=0&&adjy<m){
                        if(grid[adjx][adjy]==0&&dis+1<dist[adjx][adjy]){
                        
                            if(adjx==n-1&&adjy==n-1)return dis+1;
                            pq.push({dis+1,{adjx,adjy}});
                            dist[adjx][adjy]=dis+1;
                        
                        }
                    }
                    
                }
            }
        }   
        return -1;
    }
};