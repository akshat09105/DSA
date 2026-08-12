class Solution {
  public:
    void subset_sum(vector<int>arr,int index,int n,int sum,vector<int>&ans){
        if(index==n){
            ans.push_back(sum);
            return;
        }
        subset_sum(arr,index+1,n,sum+arr[index],ans);
        subset_sum(arr,index+1,n,sum,ans);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>ans;
        int sum=0;
        subset_sum(arr,0,n,sum,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
