class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*will be using slinding window....maximum consecutive subarray with zero<=k
         and after seeing subarray sliding window should be clicked in the mind*/
        int left=0;int right=0;int maxlen=0;int zeroes=0;
        while(right<nums.size()){
            if(nums[right]==0)zeroes++;
            while(zeroes>k){
                if(nums[left]==0)zeroes--;
                left++;
            }
            
                maxlen=max(maxlen,right-left+1);
            
            right++;
        }
        return maxlen;
    }
};