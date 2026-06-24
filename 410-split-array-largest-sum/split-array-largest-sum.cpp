class Solution {
public:
    int no_of_splits(vector<int>nums,int max_sum){
        int last_sum=nums[0];int k=1; 
        for(int i=1;i<nums.size();i++){
            if(last_sum+nums[i]>max_sum){
                k++;
                last_sum=nums[i];
            }
            else{
                last_sum+=nums[i];
            }
        }
        return k;
    }
    int splitArray(vector<int>& nums, int k) {
        int maxi=INT_MIN;int sum=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
            sum+=nums[i];
        }
        int left=maxi;int right=sum;
        while(left<=right){
            int mid=(left+right)/2;
            if(no_of_splits(nums,mid)<=k){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};