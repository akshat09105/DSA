class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());int ans=0;int x=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i-1]==nums[i])continue;
            int j=i+1;int k=nums.size()-1;
            int sum=0;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(x>abs(sum-target)){
                    x=abs(sum-target);
                    ans=sum;
                }
                
                if(sum>target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    return ans;
                }
            }

        }
        return ans;
    }
};