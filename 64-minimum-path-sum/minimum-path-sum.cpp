class Solution {
public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0&&j==0){
            return grid[i][j];
        }
        if(i<0||j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=0)return dp[i][j];
        int up=f(i-1,j,grid,dp);
        int left=f(i,j-1,grid,dp);
        return dp[i][j]=(int)min((long long)grid[i][j]+up,(long long)grid[i][j]+left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        return f(n-1,m-1,grid,dp);
    }
};