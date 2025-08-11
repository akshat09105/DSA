class Solution {
public:
    int subtractProductAndSum(int n) {
        //finding no digits
     
        int prod=1,sum=0;int z;
        while(n>0){
            z=n%10;
            n=n/10;
            prod=prod*z;
            sum=sum+z;        }
        int ans=prod-sum;
        return ans;
    }
    
};