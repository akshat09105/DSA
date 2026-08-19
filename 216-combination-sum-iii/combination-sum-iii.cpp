class Solution {
public:
    void fn(vector<vector<int>>&ans,vector<int>&ds,int k,int n,int i){
        if(ds.size()==k){
            if(n==0){
                ans.push_back(ds);
            }
            return;
        }
        for(;i<=9;i++){
            
            ds.push_back(i);
            fn(ans,ds,k,n-i,i+1);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        fn(ans,ds,k,n,1);
        return ans;
    }
};