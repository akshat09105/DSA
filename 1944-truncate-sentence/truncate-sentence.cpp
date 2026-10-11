class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        int n=s.size();int i=0;
        while(i<n){
            if(s[i]==' '){
                k--;
                if(k==0)break;
            }
            ans+=s[i];
            i++;
        }
        return ans;
    }
};