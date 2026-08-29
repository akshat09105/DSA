class Solution {
public:
    //Memoization
    int f(int i,int n,int j1,int j2,int m,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(j1<0||j1>=m||j2<0||j2>=m)return -1e8;
        if(i==n-1){
            if(j1==j2)return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2){
                    maxi=max(grid[i][j1]+f(i+1,n,j1+dj1,j2+dj2,m,grid,dp),maxi); 
                }
                else{
                    maxi=max(grid[i][j1]+grid[i][j2]+f(i+1,n,j1+dj1,j2+dj2,m,grid,dp),maxi);
                }
            }
        }
        return dp[i][j1][j2]=maxi;

    }
    int cherriPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,n,0,m-1,m,grid,dp);
    }
    //Tabulation
    int cherriiPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2)dp[n-1][j1][j2]=grid[n-1][j1];
                else dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }//base case
        int maxi=INT_MIN;
        for(int i=n-2;i>=0;i--){
            for(int j1=m-1;j1>=0;j1--){
                for(int j2=m-1;j2>=0;j2--){
                    int maxi=INT_MIN;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            if(j1+dj1>=0&&j1+dj1<=m-1&&j2+dj2>=0&&j2+dj2<=m-1){
                            if(j1==j2){
                            maxi=max(grid[i][j1]+dp[i+1][j1+dj1][j2+dj2],maxi); 
                            }
                            else{
                                maxi=max(grid[i][j1]+grid[i][j2]+dp[i+1][j1+dj1][j2+dj2],maxi);
                            }
                            }
                        }
                    } 
                    dp[i][j1][j2]=maxi; 
                }
            }
        }
        return dp[0][0][m-1];
    }
    //space Optimal
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>prev(m,vector<int>(m,-1));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2)prev[j1][j2]=grid[n-1][j1];
                else prev[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }//base case
        int maxi=INT_MIN;
        for(int i=n-2;i>=0;i--){
            vector<vector<int>>temp(m,vector<int>(m,0));
            for(int j1=m-1;j1>=0;j1--){
                for(int j2=m-1;j2>=0;j2--){
                    int maxi=INT_MIN;
                    for(int dj1=-1;dj1<=1;dj1++){
                        for(int dj2=-1;dj2<=1;dj2++){
                            if(j1+dj1>=0&&j1+dj1<=m-1&&j2+dj2>=0&&j2+dj2<=m-1){
                            if(j1==j2){
                            maxi=max(grid[i][j1]+prev[j1+dj1][j2+dj2],maxi); 
                            }
                            else{
                                maxi=max(grid[i][j1]+grid[i][j2]+prev[j1+dj1][j2+dj2],maxi);
                            }
                            }
                        }
                    } 
                    temp[j1][j2]=maxi; 
                }
            }
            prev=temp;
        }
        return prev[0][m-1];
    }
};