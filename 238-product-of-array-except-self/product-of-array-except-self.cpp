class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;int n=nums.size();int product_without_zero=1;int count=0;
        for(int i=0;i<n;i++){
            product=product*nums[i];
            if(nums[i]!=0){
                product_without_zero=product_without_zero*nums[i];
            }
            else{
                count++;
            }
        }
        vector<int>ans(n,0);
        if(count>1)return ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
            ans[i]=product/nums[i];
            }
            else{
                ans[i]=product_without_zero;
            }
        }
        return ans;
    }
};