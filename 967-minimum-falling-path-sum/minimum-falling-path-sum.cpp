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
    int miniFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,1e7));
        for(int j=0;j<n;j++){
            mini=min(mini,f(0,j,n,matrix,dp));
        }
        return mini;
    }
    //Tabulation
    int miniiFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,1e7));
        for(int j=0;j<n;j++){
            dp[n-1][j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int Downleft=INT_MAX; int Downright=INT_MAX;
                if(j>0)Downleft=matrix[i][j]+dp[i+1][j-1];
                int Down=matrix[i][j]+dp[i+1][j];
                if(j<n-1)Downright=matrix[i][j]+dp[i+1][j+1];
                dp[i][j]=min(Downleft,min(Down,Downright));
            }
        }
    
        for(int j=0;j<n;j++){
            mini=min(dp[0][j],mini);
        }
        return mini;
    }
    //space optimal
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();int mini=INT_MAX;
        vector<int>prev(n,1e7);
        for(int j=0;j<n;j++){
            prev[j]=matrix[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=n-1;j>=0;j--){
                int Downleft=INT_MAX; int Downright=INT_MAX;
                if(j>0)Downleft=matrix[i][j]+prev[j-1];
                int Down=matrix[i][j]+prev[j];
                if(j<n-1)Downright=matrix[i][j]+prev[j+1];
                curr[j]=min(Downleft,min(Down,Downright));
            }
            prev=curr;
        }
    
        for(int j=0;j<n;j++){
            mini=min(prev[j],mini);
        }
        return mini;
    }
};