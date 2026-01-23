class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       int i=0,j=0;
       vector<int>answer;
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());

       while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums2[j]<nums1[i]){
            j++;
        }
        else{
            if(answer.size()==0||nums1[i]!=answer.back()){
            answer.push_back(nums1[i]);
            }
            i++;
            j++;
        }
       }
        return answer;
    }
};