class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(j<0||j==n)return 1e7;
        if(i==n-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=1e7){
            return dp[i][j];
        }
        int Downleft=matrix[i][j]+f(i+1,j-1,n,matrix,dp);
        int Down=matrix[i][j]+f(i+1,j,n,matrix,dp);
        int Downright=matrix[i][j]+f(i+1,j+1,n,matrix,dp);
        return dp[i][j]=min(Downleft,min(Down,Downright));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,1e7));
        for(int j=0;j<n;j++){
            mini=min(mini,f(0,j,n,matrix,dp));
        }
        return mini;
    }
};