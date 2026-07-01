class Solution {
public:
    int maxDepth(string s) {
        int left=0;int right=s.size()-1;
        int count=0;int max_count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
            }
            else{
                
            }
            max_count=max(max_count,count);
        }
        return max_count;
    }
};