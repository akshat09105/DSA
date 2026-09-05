class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int sum=0;int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool NotTake=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target){
                    take=dp[i-1][target-nums[i]];
                }
                dp[i][target]=(take||NotTake);
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]==true){
            int s1=i;int s2=sum-i;
            mini=min(mini,abs(s2-s1));
            }
        }
        return mini;
    }
};