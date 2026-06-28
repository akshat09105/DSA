class Solution {
public:
    int pos_check(string &s,int &n){
        int x;
        if(s[0]=='-'){
            x=-1;
            s=s.substr(1,n);
            n--;
        }
        else if(s[0]=='+'){
            x=1;
            s=s.substr(1,n);
            n--;
        }
        else{
            x=1;
        }
        return x;
    }
    int myAtoi(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                s=s.substr(i,n);
                break;
            }
            
        }
        n=s.size();
        long long ans=0;
        int pos=pos_check(s,n);//if pos is 1 then number is positive or -1 if number i -ve
        for(int i=0;i<n;i++){
            if((s[i]-'0')>=0&&(s[i]-'0')<=9){
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX){
                    if(pos==-1){
                        return INT_MIN;
                    }
                    else{
                        return INT_MAX;
                    }
                }
            }
            else{
                break;
            }
        }
        ans=ans*pos;
        
       return ans;

        
    }
};