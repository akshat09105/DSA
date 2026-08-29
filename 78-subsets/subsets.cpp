class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();vector<vector<int>>ans;
        for(int i=0;i<pow(2,n);i++){
            vector<int>ls;
            for(int index=0;index<n;index++){
                if(i&1<<index){
                    ls.push_back(nums[index]);
                }
            }
            ans.push_back(ls);
        }
        return ans;
    }
};