class Solution {
public:
    string reverse(string s){
        int l=0;int r=s.size()-1;
        while(l<=r){
            swap(s[l],s[r]);
            l++;r--;
        }
        return s;
    }
    int minInsertions(string s) {
        string r=reverse(s);
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(r[j-1]==s[i-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int longest_pp=dp[n][n];
        return n-longest_pp;
    }
};