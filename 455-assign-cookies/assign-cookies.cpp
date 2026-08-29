class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;int n=g.size();
        int r=0;int m=s.size();
        int count=0;
        while(l<n&&r<m){
            if(g[l]<=s[r]){
                count++;
                r++;
                l++;
            }
            else{
                r++;
            }
        }
        return count;

    }
};