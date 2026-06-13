class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini=nums[0];vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini){
                mini++;
            }
            else{
                ans.push_back(mini);
                mini++;
                i--;
            }
        }
        return ans;
    }
};