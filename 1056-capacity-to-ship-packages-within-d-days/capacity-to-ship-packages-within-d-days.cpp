class Solution {
public:
    int ship_capable(vector<int>&weights,int cap){
        int days=0;int x=cap;
        for(int i=0;i<weights.size();i++){
            x-=weights[i];
            if(i==weights.size()-1 && x>0){
            
                days++;
              
            }
            if(x==0){
                days++;
                x=cap;
            }
            else if(x<0){
                days++;
                x=cap;
                i--;
            }
            
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum=0;int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int left=maxi;int right=sum;int ans;
        while(left<=right){
            int mid=(left+right)/2;
            if(ship_capable(weights,mid)<=days){
                ans=mid;
                right=mid-1;//decreasing capacity there by increasing days
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};