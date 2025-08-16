class Solution {
public:
    bool isPalindrome(int x) {
        //finding total no of digits
        if(x>0){
        int s=x;int n=x;int digits=0;long int sum=0;
        while(n!=0){
            n=n/10;
            digits=digits+1;
        }
        int d=digits;
        for(int i=digits;i>0;i--){
            int sum1=1;
            long int digit=s%10;
            for(int i=d-1;i>0;i--){
                sum1=10*sum1;
            }
            d--;
            sum=sum+digit*sum1;
            s=s/10;
            
        }
        if(x==sum){
            return true;
        }
        else{
            return false;
        }
        }
        
        else if(x==0){
            return true;
        }
        
        
        else{
            return false;
        }
    }
    
    
};