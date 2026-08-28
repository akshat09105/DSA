class Solution {
public:
    int f(int i,int j,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int d=f(i+1,j,triangle,n,dp)+triangle[i][j];
        int dg=f(i+1,j+1,triangle,n,dp)+triangle[i][j];
        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //greedy not possible as it's not consistant either increasing or decreaasing
        //thereforce recurssion
        //here we will start it from top as it is moving from bottom
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return f(0,0,triangle,n,dp);

    }
};