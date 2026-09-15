class Solution {
public:
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
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,text1,text2,dp);
    }
};