class Solution {
public:
    //Memoization
    int ff(int index1,int index2,string& text1, string& text2,vector<vector<int>>&dp){
        if(index1<0||index2<0)return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(text1[index1]==text2[index2]){
            return dp[index1][index2]=1+f(index1-1,index2-1,text1,text2,dp);
        }
        return dp[index1][index2]=max(f(index1-1,index2,text1,text2,dp),f(index1,index2-1,text1,text2,dp));
    }
    int longestcommonSubsequence(string text1, string text2) {
        int n=text1.size();int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return ff(n-1,m-1,text1,text2,dp);
    }
    //index shifting
    int f(int index1,int index2,string& text1, string& text2,vector<vector<int>>&dp){
        if(index1==0||index2==0)return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(text1[index1-1]==text2[index2-1]){
            return dp[index1][index2]=1+f(index1-1,index2-1,text1,text2,dp);
        }
        return dp[index1][index2]=max(f(index1-1,index2,text1,text2,dp),f(index1,index2-1,text1,text2,dp));
    }
    int longestCommonsubsequence(string text1, string text2) {
        int n=text1.size();int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,text1,text2,dp);
    }
    //Tabulation
    int LongestCommonSubsequence(string text1, string text2) {
        int n=text1.size();int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int index1=1;index1<=n;index1++){
            for(int index2=1;index2<=m;index2++){
                if(text1[index1-1]==text2[index2-1]){
                    dp[index1][index2]=1+dp[index1-1][index2-1];
                }
                else{
                dp[index1][index2]=max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }
        return dp[n][m];
    }
    //space optimal
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();int m=text2.size();
        vector<int>prev(m+1,0);
        for(int j=0;j<=m;j++)prev[j]=0;
        for(int index1=1;index1<=n;index1++){
            vector<int>curr(m+1,0);
            for(int index2=1;index2<=m;index2++){
                if(text1[index1-1]==text2[index2-1]){
                    curr[index2]=1+prev[index2-1];
                }
                else{
                curr[index2]=max(prev[index2],curr[index2-1]);
                }
            }
            prev=curr;
        }
        return prev[m];
    }

};