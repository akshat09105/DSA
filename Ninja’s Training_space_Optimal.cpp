//Tabulation

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>dp(4,0);
    dp[0]=max(points[0][1],points[0][2]);
    dp[1]=max(points[0][0],points[0][2]);
    dp[2]=max(points[0][0],points[0][1]);
    dp[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int>temp(4,0);
        for(int last=0;last<4;last++){
            int maxi=0;
            for(int i=0;i<=2;i++){
                if(i!=last){
                    int point=points[day][i]+dp[i];
                    maxi=max(maxi,point);
                }
            }
            temp[last]=maxi;
        }
        dp=temp;
    }
    return dp[3];
}
