class Solution {
public:
    int divisor_sum(vector<int>nums,int div){
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/div);
        }
        return (int)sum;

    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        /*typical bs on answer problem needed to find minimum value of divisor which passes the
         threshold condition*/
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int left=1;int right=maxi;int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(divisor_sum(nums,mid)<=threshold){
                ans=mid;
                right=mid-1;            
            }
            else{
                left=mid+1;
            }
        }
        return ans;
        
    }
};