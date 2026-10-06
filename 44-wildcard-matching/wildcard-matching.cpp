class Solution {
public:
    //memoization with shifting
    int f(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(i==0&&j==0)return true;
        if(i==0)return false;
        if(j==0){
            for(int ii=1;ii<=i;ii++){
                if(s[ii-1]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i-1]==p[j-1]||s[i-1]=='?'){
            return dp[i][j]=f(s,p,i-1,j-1,dp);
        }
        if(s[i-1]=='*'){
            return dp[i][j]=f(s,p,i-1,j,dp)||f(s,p,i,j-1,dp);
        }
        return dp[i][j]=false;
    }
    bool ismatch(string p, string s) {
        int n=s.size();int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(s,p,n,m,dp);
    }
    //tabulation
    bool isMatch(string p, string s) {
        int n=s.size();int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int j=1;j<=m;j++)dp[0][j]=false;//case for i=0
        for(int i=1;i<=n;i++){//case for j=0
            bool flag=true;
            for(int ii=1;ii<=i;ii++){
                if(s[ii-1]!='*'){
                    flag=false;
                }
            }
            dp[i][0]=flag;
        }
        //base case is done now
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||s[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(s[i-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
                else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};