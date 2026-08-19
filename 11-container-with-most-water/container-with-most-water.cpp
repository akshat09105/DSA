class Solution {
public:
    int maxArea(vector<int>& height) {
        int right=height.size()-1;
        int left=0;long long ans=-1;long long area=0;
        while(left<right){
            area=(long long)(right-left)*min(height[left],height[right]);
            ans=max(ans,area);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return (int)ans;
    }
};