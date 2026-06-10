class Solution {
public:
    long long hours_taken(vector<int>piles,int n){
        long long h=0;

        for(int i=0;i<piles.size();i++){
            h +=ceil((double)piles[i]/(double)n);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
     int maxi=0;
     for(int i=0;i<piles.size();i++){
        maxi=max(maxi,piles[i]);
     }
     int ans;
     int left=1;int right=maxi;
     while(left<=right){
        int mid=(left+right)/2;
        if(hours_taken(piles,mid)<=h){
            ans=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
     }
     return ans;
    }
};