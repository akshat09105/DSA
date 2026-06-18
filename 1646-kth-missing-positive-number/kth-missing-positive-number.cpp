class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      /*there is BS on answer can be applied in this question as no min or max needs to
      found*/
      /*but BS search needs can be applied as we need to search in sorted in array so bs clicked*/
      int left=0;int right=arr.size()-1;
      while(left<=right){
        int mid=(left+right)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
      }
      return k+(right+1);


    }
};