class Solution {
public:
    void reverse(vector<string>&st){
        int n=st.size();
        int left=0;int right=n-1;
        while(left<=right){
            swap(st[left],st[right]);
            left++;right--;
        }
    }
    string reverseWords(string s) {
        vector<string>st;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                s=s.substr(i,n);
                break;
            }
        }
        n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                s=s.substr(0,i+1);
                break;
            }
        }
        n=s.size();
        string p;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(p.size()!=0){
                st.push_back(p);
                }
                p.clear();
            }
            else{
                p.push_back(s[i]);
            }
        }
        st.push_back(p);
        reverse(st);
        string ans;
        for(int i=0;i<st.size();i++){
            for(int j=0;j<st[i].size();j++){
                ans.push_back(st[i][j]);
            }
            if(i<st.size()-1){
            ans.push_back(' ');
            }
        }
        return ans;
    }
};