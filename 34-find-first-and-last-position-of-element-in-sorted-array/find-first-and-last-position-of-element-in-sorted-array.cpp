class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result = {-1, -1};
    
    // 1. First Position dhoondne ke liye
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2; // Overflow se bachne ke liye better way
        if (nums[mid] == target) {
            result[0] = mid;      // Potential answer mil gaya
            right = mid - 1;      // Par left mein check karte raho "extreme left" ke liye
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // 2. Last Position dhoondne ke liye (Sirf tab dhoondo agar pehla mil gaya ho)
    if (result[0] != -1) {
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                result[1] = mid;  // Potential answer mil gaya
                left = mid + 1;   // Par right mein check karte raho "extreme right" ke liye
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return result;
}
};