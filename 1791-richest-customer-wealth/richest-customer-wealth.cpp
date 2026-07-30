class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       int m=accounts.size();
       int n=accounts[0].size();//m*n matrix
       int Max_wealth=INT_MIN,wealth=0;
       for(int i=0;i<m;i++){
        wealth=0;
        for(int j=0;j<n;j++){
            wealth+=accounts[i][j];
        }
        Max_wealth=max(Max_wealth,wealth);
       }
       return Max_wealth;

    }
};