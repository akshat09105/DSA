class Solution {
public:
    bool MagnetCanPut(vector<int>&position,int m,int dist){
        int Magnet=1;int last=position[0];
        for(int i=1;i<position.size();i++){
            if(position[i]-last>=dist){
                Magnet++;
                last=position[i];
                if(Magnet==m){
                    return true;
                }
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left=1;int n=position.size();
        int right=position[n-1]-position[0];int ans=1;
        while(left<=right){
            int mid=(left+right)/2;
            if(MagnetCanPut(position,m,mid)==true){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};