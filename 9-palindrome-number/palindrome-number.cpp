class Solution {
public:
    bool isPalindrome(int x) {
        int p=x;
        if(x<0){

            return  0;
        }
        
        int s;long int ans=0;int count=0;
        while(x>0){
            s=x%10;
            ans=ans*10+s;
            x=x/10;
            count++;

        }
        return (ans==p);

    }
};