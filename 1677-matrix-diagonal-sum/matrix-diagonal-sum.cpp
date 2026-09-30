class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        //analyzed that left diagonal has relationship that i+j==(n-1)
        //obviously right diagonal has relationship of i==j
        int sum=0;
        int n=mat.size();int i=0;int j=n-1;
        while(i<n&&j>=0){
            sum+=mat[i][i];
            sum+=mat[n-1-j][j];
            i++;j--;
        }
        
        
        if(n%2!=0){
        sum-=mat[n/2][n/2];
        }
        return sum;
    }
};