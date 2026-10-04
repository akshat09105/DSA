class Solution {
public:
    //memoization
    int f(string s,string t,int ind1,int ind2,vector<vector<int>>&dp){
        if(ind2<0)return 1;
        if(ind1<0)return 0;
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        //exploring all cases
        if(s[ind1]==t[ind2]){
            return dp[ind1][ind2]=f(s,t,ind1-1,ind2-1,dp)+f(s,t,ind1-1,ind2,dp);
        }
        return dp[ind1][ind2]=f(s,t,ind1-1,ind2,dp);
    }
    int numDisTinct(string s, string t) {
        int n=s.size();int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(s,t,n-1,m-1,dp);
    }
    //tabulation
    int numDistinct(string s, string t) {
        int n=s.size();int m=t.size();
        //have to do shiting to solve this as ind1 and ind2 can't be -1
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==t[ind2-1]){
                    dp[ind1][ind2]=dp[ind1-1][ind2-1]+dp[ind1-1][ind2];
                }
                else dp[ind1][ind2]=dp[ind1-1][ind2];
            }
        }
        return (int)dp[n][m];
    }
};