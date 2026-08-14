class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int l = 0;
        int sum = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while (sum > k) {
                sum -= nums[l];
                l++;
            }

            // All subarrays ending at r
            // starting from l to r are valid
            ans += (r - l + 1);
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};