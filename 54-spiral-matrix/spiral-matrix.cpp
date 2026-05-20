class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    //left matrix be (m*n) 
    int m=matrix.size();
    int n=matrix[0].size();
    int top=0,left=0,right=n-1,bottom=m-1;//m was no of rows
    vector<int>ans;
    while(top<=bottom && left<=right){
    /*agar kbhi bhi top>bottom ya left>right hota hai mtlb saare element dekh liye hai 
    matrix ke seen this  by samjke*/
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){//kyuki top right dono change hua toh condition check krna zaruri hai 
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
        }
        return ans;
    }
};