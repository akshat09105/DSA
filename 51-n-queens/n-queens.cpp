class Solution {
public:
    bool isSafe(int row,int col,vector<int>&hash_row,vector<int>&hash_upperdig,vector<int>&hash_lowerdig,int n){
        //check row
        if(hash_row[row]==1){
            return false;
        }
        if(hash_lowerdig[row+col]==1){
            return false;
        }
        if(hash_upperdig[n-1+col-row]==1){
            return false;
        }
        return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&hash_row,vector<int>&hash_upperdig,vector<int>&hash_lowerdig){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,hash_row,hash_upperdig,hash_lowerdig,n)){
                hash_row[row]=1;
                hash_lowerdig[row+col]=1;
                hash_upperdig[n-1+col-row]=1;
                board[row][col]='Q';
                solve(col+1,board,ans,n,hash_row,hash_upperdig,hash_lowerdig);
                hash_row[row]=0;
                hash_lowerdig[row+col]=0;
                hash_upperdig[n-1+col-row]=0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        vector<int>hash_row(n);
        vector<int>hash_upperdig(2*n-1);
        vector<int>hash_lowerdig(2*n-1);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n,hash_row,hash_upperdig,hash_lowerdig);
        return ans;
    }
};