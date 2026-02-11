class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //applying mools voting algo
        int el;int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                el=nums[i];
            }
            if(el==nums[i]){
                count++;
            }
            else{
                count--;
            }

        }
        return el;
    }
};