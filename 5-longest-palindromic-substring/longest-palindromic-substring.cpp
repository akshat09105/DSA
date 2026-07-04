class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen=1;int start=0;
        if(n==0){
            return "";
        }
        for(int i=0;i<n;i++){
            int left=i;int right=i;
            while(left>=0&&right<n&&s[left]==s[right]){
                if(right-left+1>maxlen){
                    maxlen=right-left+1;
                    start=left;
                }
                right++;left--;
            }
            left=i;right=i+1;
            while(left>=0&&right<n&&s[left]==s[right]){
                if(right-left+1>maxlen){
                    maxlen=right-left+1;
                    start=left;
                }
                left--;right++;
            }
        }

        return s.substr(start, maxlen);
    }
};