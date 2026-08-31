class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        int x=sum/2;
        vector<bool>prev(x+1,0);
        if(nums[0]<=x){
        prev[nums[0]]=true;
        }
        prev[0]=true;
        for(int i=1;i<nums.size();i++){
            vector<bool>curr(x+1,0);
            curr[0]=true;
            for(int target=1;target<=x;target++){
                bool not_take=prev[target];
                bool take=false;
                if(nums[i]<=target)take=prev[target-nums[i]];
                curr[target]=(not_take||take);
            }
            prev=curr;
        }
        return prev[x];
    }
};