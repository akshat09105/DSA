class Solution {
public:
    //memoization space shift to help tabulation
    int f(string &word1, string &word2,int i,int j,vector<vector<int>>&dp){
        if(i==0)return j;
        if(j==0)return i;
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i-1]==word2[j-1])return 0+f(word1,word2,i-1,j-1,dp);
        int p1=1+f(word1,word2,i,j-1,dp);
        int p2=1+f(word1,word2,i-1,j,dp);
        int p3=1+f(word1,word2,i-1,j-1,dp);
        return dp[i][j]=min(p1,min(p2,p3));    
    }
    int mindistance(string word1, string word2) {
        int n=word1.size();int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(word1,word2,n,m,dp);
    }
    //tabulation
    int minDistance(string word1, string word2) {
        int n=word1.size();int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=0+dp[i-1][j-1];
                else{ 
                    int p1=1+dp[i][j-1];
                    int p2=1+dp[i-1][j];
                    int p3=1+dp[i-1][j-1];
                
                    dp[i][j]=min(p1,min(p2,p3));
                }
            }
        }
        return dp[n][m];
    }
};