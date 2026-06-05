class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //applying mools voting algo
        int cnt=0;int el;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                el=nums[i];
            }
            if(el==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return el; 
        /*checking if there a majority element exist of not....if majority element exist el will represent that only
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(el==nums[i]){
                cnt++;
            }
        }
        if(cnt>(nums.size()/2)){
            return el;
        }
        return -1;
        */
   }
};