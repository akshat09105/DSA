class Solution {
public:
    pair<int, int> findFloorCeil(const vector<int>& arr, int k) {
        //typical problem of finding a number in a sorted array therefore implementing Binary search
        int left=0;
        int n=arr.size();
        int right=n-1;
        int mid;
        int floor=-1;
        int ceil=-1;
        //finding ceil first
        while(left<=right){
            mid=(left+right)/2;
            if(arr[mid]>=k){
                ceil=arr[mid];
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        //finding floor typical problem of finding a number in a sorted array therefore implementing Binary search
        //arr[mid]<=target 
        //note koi bhi element repeat nhi ho raha hai isliye kbhi koi problem nhi ayegi
        left=0;right=n-1;
        while(left<=right){
            mid=(left+right)/2;
            if(arr[mid]<=k){
                floor=arr[mid];
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        pair<int,int>ans;
        ans={floor,ceil};
        return ans;
    }
};
