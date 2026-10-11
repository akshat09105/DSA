class Solution {
public:
    string reverse(string s){
        int l=0;int r=s.size()-1;
        while(l<=r){
            swap(s[l],s[r]);
            l++;r--;
        }
        return s;
    }
    string reverseWords(string s) {
        int left=0;int right=0,i=0;int n=s.size();string ans;
        while(i<=n){
            if(s[right]==' '||i==n){
                ans+=reverse(s.substr(left,right-left));
                left=right+1;
                if(i<n){
                    ans+=' ';
                }
            }
            
            
            i++;right++;
        }
        return ans;
    }
};