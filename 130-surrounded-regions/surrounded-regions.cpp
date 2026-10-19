class Solution {
public:
    bool check(int nRow,int nCol,int n,int m){
        if(nRow>=0&&nRow<n&&nCol>=0&&nCol<m){
            return true;
        }
        return false;
    }
    void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& mat,int n,int m){
        vis[i][j]=1;
        int dRow[]={-1,0,+1,0};
        int dCol[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int nRow=i+dRow[k];
            int nCol=j+dCol[k];
            if(check(nRow,nCol,n,m)&&mat[nRow][nCol]=='O'&&!vis[nRow][nCol]){
                dfs(nRow,nCol,vis,mat,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){//column wise traversal first we are doing
            if(mat[i][0]=='O'&&vis[i][0]==0){
                dfs(i,0,vis,mat,n,m);
            }
            if(mat[i][m-1]=='O'&&vis[i][m-1]==0){
                dfs(i,m-1,vis,mat,n,m);
            }
        }
        for(int j=0;j<m;j++){//col wise
            if(mat[0][j]=='O'&&vis[0][j]==0){
                dfs(0,j,vis,mat,n,m);
            }
            if(mat[n-1][j]=='O'&&vis[n-1][j]==0){
                dfs(n-1,j,vis,mat,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    mat[i][j]='X';
                }
            }
        }
    }
};