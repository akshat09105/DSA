class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int x=0;int sum=0;
        for(auto c:s){
            if(x==0){
                sum+=(c-'0');
                x=1;
            }
            else{
                sum-=(c-'0');
                x=0;
            }

        }
        return sum;
    }
};