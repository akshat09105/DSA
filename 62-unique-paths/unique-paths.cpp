class Solution {
public:
    //now applying memoization
    int f(int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0){
            return 1;
        }
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=0)return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    //now applying space optimization
    int uniquePaths(int m, int n) {
        //all paths need to be find to recurssion is clicked->TC-:2^(m*n)
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    temp[j]=1;
                    continue;
                }
                int up=0;int left=0;
                if(i>0)up=prev[j];
                if(j>0)left=temp[j-1];
                temp[j]=up+left;
            }
            prev=temp;
        }
        return prev[n-1];
    }
};