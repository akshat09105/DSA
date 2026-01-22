class Solution {
public:
    void reverse(vector<int>&arr,int start,int end){
        while(start<=end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }
};