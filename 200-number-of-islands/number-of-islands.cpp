class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>& grid,int m,int n,vector<vector<int>>&vis){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delRow=-1;delRow<=1;delRow++){
                if(delRow==0)continue;

                int nrow=row+delRow;
                int ncol=col;
                if(nrow>=0 && nrow<m && ncol>=0&& ncol<n && grid[nrow][ncol]=='1' && vis[nrow][ncol]!=1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});                    
                }
                
            }
            for(int delCol=-1;delCol<=1;delCol++){
                if(delCol==0)continue;
                int nrow=row;
                int ncol=col+delCol;
                if(nrow>=0 && nrow<m && ncol>=0&& ncol<n && grid[nrow][ncol]=='1' && vis[nrow][ncol]!=1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&vis[i][j]!=1){
                    bfs(i,j,grid,m,n,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};