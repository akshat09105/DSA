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
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(i==0&&j==0)temp[j]=grid[i][j];
                else{
                    int up=INT_MAX;int left=INT_MAX;
                    if(i>0){
                        up=prev[j];
                    }
                    if(j>0){
                        left=temp[j-1];
                    }
                    temp[j]=(int)min((long long)up+grid[i][j],(long long)left+grid[i][j]);
                }
            }
            prev=temp;
        }
        return prev[m-1];
    }
};