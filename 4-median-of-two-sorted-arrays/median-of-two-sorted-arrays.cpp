class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();int n2=nums2.size();
        if(n1>n2){// i want n1 to be of lesser size
            return findMedianSortedArrays(nums2,nums1);
        }
        int leftside=(n1+n2+1)/2;/*int terms of odd element we have left side
                                 more elements only*/
        int left=0;
        int right=n1;
        int n=n1+n2;
        while(left<=right){
            int mid1=(left+right)/2;
            int mid2=leftside-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1>0) l1=nums1[mid1-1];
            if(mid2>0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==0){
                    return ((double)max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return (double)max(l1,l2);
                }
            }
            else if(l1>r2){
                right=mid1-1;
            }
            else{
                left=mid1+1;
            }
        }
        return -1;
    }
};