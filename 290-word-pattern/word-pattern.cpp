class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int i=0;int j=0;
        unordered_map<char,string>mpp1;unordered_map<string,char>mpp2;
        int n1=pattern.size();int n2=s.size();
        while(i<pattern.size()&&j<s.size()){
            int start=j;int end=j;
            while(end<s.size()&&s[end]!=' '){
                end++;
            }
            int length=end-start;string temp=s.substr(start,length);
            if(mpp1.find(pattern[i])!=mpp1.end()&&mpp1[pattern[i]]!=temp){
                
            return false;
                
            }
            if(mpp2.find(temp)!=mpp2.end()&&mpp2[temp]!=pattern[i]){
                return false;
            }
            mpp1[pattern[i]]=temp;
            mpp2[temp]=pattern[i];
            i++;j=end+1;
            
        }
        if(i!=n1||j!=n2+1)return false;
        return true;
    }
};