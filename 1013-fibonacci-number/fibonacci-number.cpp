class Solution {
public:
    int fib(int n) {
        int a=0,b=1,s;
        for(int i=0;i<n;i++){
            s=a+b;
            a=b;
            b=s;
        }
        return a;

        
    }
};