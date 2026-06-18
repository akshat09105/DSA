class Solution {
public:
    int ship_capable(vector<int>&weights,int cap){
       int load=0;int days=1;
       for(int i=0;i<weights.size();i++){
           if(load+weights[i]>cap){
            days++;
            load=weights[i];
           }
           else{
            load+=weights[i];
           }
       }
       return days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;int sum=0;
        for(int i=0;i<weights.size();i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }
        int left=maxi;int right=sum;int mid;int ans=-1;
        while(left<=right){
            mid=(left+right)/2;
            if(ship_capable(weights,mid)<=days){
                right=mid-1;
                ans=mid;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};