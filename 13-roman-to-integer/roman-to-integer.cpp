class Solution {
public:
    int romantointeger(char c){
        if(c=='I'){
            return 1;
        }
        else if(c=='V'){
            return 5;
        }
        else if(c=='X'){
            return 10;
        }
        else if(c=='L'){
            return 50;
        }
        else if(c=='C'){
            return 100;
        }
        else if(c=='D'){
            return 500;
        }
        return 1000; 
    }
    int romanToInt(string s) {
        char last=s[0];
        int sum=romantointeger(last);
        for(int i=1;i<s.size();i++){
            char current=s[i];
            if(last=='I'){
                if(current=='V'){
                    sum-=1;
                    sum+=4;
                    last=current;
                }
                else if(current=='X'){
                    sum-=1;
                    sum+=9;
                    last=current;
                }
                else{
                    sum+=romantointeger(current);
                    last=current;
                }
            }
            else if(last=='X'){
                if(current=='L'){
                    sum-=10;
                    sum+=40;
                    last=current;
                }
                else if(current=='C'){
                    sum-=10;
                    sum+=90;
                    last=current;
                }
                else{
                    sum+=romantointeger(current);
                    last=current;
                }
            }
            else if(last=='C'){
                if(current=='D'){
                    sum-=100;
                    sum+=400;
                    last=current;
                }
                else if(current=='M'){
                    sum-=100;
                    sum+=900;
                    last=current;
                }
                else{
                    sum+=romantointeger(current);
                    last=current;
                }
            }
            else{
                sum+=romantointeger(current);
                last=current;
            }
        }
        return sum;
    }
};