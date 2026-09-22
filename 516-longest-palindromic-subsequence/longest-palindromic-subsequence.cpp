class Solution {
public:
    string reverse(string s){
        int r=s.size()-1;
        int l=0;
        while(l<=r){
            swap(s[l],s[r]);
            l++;r--;
        }
        return s;
    }
    int longestPalindromeSubseq(string s) {
        string rs=reverse(s);
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==rs[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};