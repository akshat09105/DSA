class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        //analyzed that left diagonal has relationship that i+j==(n-1)
        //obviously right diagonal has relationship of i==j
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j||(i+j)==n-1){
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
};