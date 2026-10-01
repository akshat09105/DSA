class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        //we need to find LCS as LCS element needs to be added once 
        int n=s1.size();//s1
        int m=s2.size();//s2
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return n+m-dp[n][m];
    }
};
