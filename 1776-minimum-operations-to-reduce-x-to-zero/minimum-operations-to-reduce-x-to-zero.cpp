class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //sliding windowss is
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        //if i can find maximum length having sum(num)-x then i get shortest way operation x
        int find=sum-x;int l=0;int r=0;
        int maxlen=-1;
        sum=0;
        while(r<n){
            
            sum+=nums[r];
            
            while(l<=r&&sum>find){
                sum-=nums[l];
                l++;
            }
            if(sum==find)maxlen=max(maxlen,r-l+1);
            r++;
        }
        if(maxlen==-1)return -1;
        return (n-maxlen);
    }
};