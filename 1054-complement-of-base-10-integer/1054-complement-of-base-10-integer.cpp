class Solution {
public:
    int bitwiseComplement(int n) {
        int j,i=0,sum=0;
        if(n==0){
            return 1;
        }
        while(n!=0){
            j=n&1;
            n=n>>1;
            
            if(j==0){
                sum=sum+1*pow(2,i);
            }
            else{
                sum=sum+0*pow(2,i);
            }
            i=i+1;
            

        }

        
        return sum;
        
    }
};