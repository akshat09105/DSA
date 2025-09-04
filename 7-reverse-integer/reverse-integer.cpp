class Solution {
public:
    int reverse(int x) {
    int n=x;int a=0;long int sum=0;
       
            //first finding no of digits
            
            while(n!=0){
                n=n/10;
                a=a+1;
            }
            //a is not digits
            for(int i=a-1;i>=0;i--){
                
                int d=x%10;
                sum=(int)d*pow(10,i)+sum;
                x=x/10;
           
            }
             if(sum>INT_MAX || sum<INT_MIN){
               return 0; 
            }
            return sum;    
}
};