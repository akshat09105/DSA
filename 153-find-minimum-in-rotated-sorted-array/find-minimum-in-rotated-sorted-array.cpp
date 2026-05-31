class Solution {
public:
    int findMin(vector<int>& arr) {
        //search in sorted array therefore BS is clicked
        int left=0;int right=arr.size()-1;int ans=INT_MAX;int mid;
        while(left<=right){
            mid=(left+right)/2;
            ans=min(ans,arr[mid]);
            if(arr[mid]>=arr[left]){//array is left sorted
                if(arr[left]>arr[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            else{//right sorted
                right=mid-1;
            }
        }   
        return ans;     
    }
};