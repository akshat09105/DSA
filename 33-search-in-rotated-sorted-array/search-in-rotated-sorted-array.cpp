class Solution {
public:
    int search(vector<int>& arr, int target) {
        int left=0,right=arr.size()-1;int ans=-1;int mid;int index;
        while(left<=right){
            mid=(left+right)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>=arr[left]){//mid is left alligned
                if(target<=arr[mid] && target>=arr[left]){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{//mid is left allinged
                if(target>=arr[mid] && target<=arr[right]){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }

            }
        }
        return ans;

    }
};