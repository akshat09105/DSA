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
    //sppace_optimized
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0&&j==0){
                    temp[j]=1;
                    continue;
                }
                if(obstacleGrid[i][j]==1){
                    temp[j]=0;
                    continue;
                }
                int up=0;int left=0;
                if(i>0)up=prev[j];
                if(j>0)left=temp[j-1];
                temp[j]=up+left;
            }
            prev=temp;
        }
        return prev[m-1];
    }
};