class Solution {
  public:
  void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis,vector<pair<int,int>>&island,int row0,int col0,int delrow[],int delcol[],int n,int m){
      vis[row][col]=1;
      island.push_back({row-row0,col-col0});
      for(int i=0;i<4;i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='L'){
              dfs(nrow,ncol,grid,vis,island,row0,col0,delrow,delcol,n,m);
          }
      }
  }
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&grid[i][j]=='L'){
                vector<pair<int,int>>island;
                dfs(i,j,grid,vis,island,i,j,delrow,delcol,n,m);
                st.insert(island);
                }
            }
        }
        return st.size();
        
    }
};
