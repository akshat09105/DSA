#include <bits/stdc++.h>
//recurssion
//memoization
bool f(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0){
        return true;
    }
    if(index==0){
        if(arr[index]==target){
            return true;
        }
        return false;
    }
    if(dp[index][target]!=-1)return dp[index][target];
    bool notTake=f(index-1,target,arr,dp);
    bool take=false;
    if(arr[index]<=target){
        take=f(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=(take||notTake);
    

} 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}
