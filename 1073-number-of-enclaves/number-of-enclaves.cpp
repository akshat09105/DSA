class Solution {
public:
    bool check(int i,int j,int n,int m){
        if(i>=0&&i<n&&j>=0&&j<m){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>& grid,int delRow[],int delCol[],int n,int m){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=i+delRow[k];
            int ncol=j+delCol[k];
            if(check(nrow,ncol,n,m)&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid,delRow,delCol,n,m);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //dfs on every-boundary 
        int delRow[]={-1,0,+1,0};
        int delCol[]={0,+1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){//seeing outer 2 columns 
            if(grid[i][0]==1&&vis[i][0]==0){
                dfs(i,0,vis,grid,delRow,delCol,n,m);
            }
            if(grid[i][m-1]==1&&vis[i][m-1]==0){
                dfs(i,m-1,vis,grid,delRow,delCol,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1&&vis[0][j]==0){
                dfs(0,j,vis,grid,delRow,delCol,n,m);
            }
            if(grid[n-1][j]==1&&vis[n-1][j]==0){
                dfs(n-1,j,vis,grid,delRow,delCol,n,m);
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;

    }
};