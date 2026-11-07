class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, vector<int> &src, vector<int> &dest) {
        // code here
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src[0],src[1]}});
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[src[0]][src[1]]=0;
        int dx[]={0,1,0,-1};
        int dy[]={-1,0,+1,0};
        if(src[0]==dest[0]&&src[1]==dest[1]&&grid[src[0]][src[1]])return 0;
        if(src[0]==dest[0]&&src[1]==dest[1])return -1;
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int x=it.second.first;int y=it.second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=x+dx[i];int newc=y+dy[i];
                if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr][newc]==1&&dis+1<dist[newr][newc]){
                    dist[newr][newc]=dis+1;
                    if(newr==dest[0]&&newc==dest[1])return dis+1;
                    q.push({dis+1,{newr,newc}});
                    
                }
            }
        }
        return -1;
    }
};
