class Solution {
public:
    //now recurssion converting it to memoization
    int f(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        if(i==0&&j==0)return 1;
        if(i<0||j<0){
            return 0;
        }
        if(obstacleGrid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=f(i-1,j,obstacleGrid,dp);
        int left=f(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    dp[i][j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                int up=0;int left=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[n-1][m-1];
    }
};