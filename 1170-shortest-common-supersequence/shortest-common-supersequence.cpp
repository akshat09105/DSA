class Solution {
public:
    string reverse(string s){
        int r=s.size()-1;int l=0;
        while(l<=r){
            swap(s[r],s[l]);
            l++;r--;
        }
        return s;
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size();//s1->vertical in dp table
        int m=s2.size();//s2->horizontal in dp table
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //tracing it back to get superString here will not just print LCS here we print all but will focus if elements are part of LCS will be printed once
        string ans="";
        int i=n;int j=m;
        while(i>0&&j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        while(i>0)ans+=s1[i-1],i--;
        while(j>0)ans+=s2[j-1],j--;
        return reverse(ans);
        
    }
};