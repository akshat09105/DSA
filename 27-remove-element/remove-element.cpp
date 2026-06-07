class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;int k;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                k=i;
                break;
            }
        }
        for(int i=k+1;i<nums.size();i++){
            if(nums[i]!=val){
                swap(nums[i],nums[k]);
                k++;
                
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                count++;
            }
        }
        return nums.size()-count;
    }
};