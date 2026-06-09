class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,m=nums.size()-1;
                while(k<m){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[m];
                    if(sum>target){
                        m--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        vector<int>temp={nums[i],nums[j],nums[k],nums[m]};
                        ans.push_back(temp);
                        k++;
                        m--;
                        while(k<m && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<m && nums[m]==nums[m+1]){
                            m--;
                        }
                    }
                }
            }
        }
        return ans;

    }
};