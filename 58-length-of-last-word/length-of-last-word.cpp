class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;bool flag;int last=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                length++;
                last=length;
                
            }
            else{
                length=0;
            }
        }
        return last;
    }
};