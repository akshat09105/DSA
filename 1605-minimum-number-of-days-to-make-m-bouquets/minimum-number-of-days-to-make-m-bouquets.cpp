class Solution {
public:
    bool total_flowers(vector<int>bloomDay,int days,int m,int k){
        int kk=k;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=days){
                kk--;
            }
            else{
                kk=k;
            }
            if(kk==0){
                m--;
                kk=k;
            }
            
        }
        if(m<=0){
            return true;
        }
        return false;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
        }
        int left=1;int right=maxi;int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(total_flowers(bloomDay,mid,m,k)){
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