//memoization
int f(int day,int last,vector<vector<int>>&arr,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(arr[day][i],maxi);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1)return dp[day][last];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int points=arr[day][i]+f(day-1,i,arr,dp);
            maxi=max(maxi,points);
        }
    }
    return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}
