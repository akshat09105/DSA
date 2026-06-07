class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        long long left=1,right=x;
        int ans=1;
        long long mid;
        while(left<=right){
            mid=left+right;
            mid=mid/2;
            if(mid*mid<=x){
                ans=mid;
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};