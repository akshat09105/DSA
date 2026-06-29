class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            auto it=mpp.find(s[i]);
            if(it==mpp.end()){
                for(auto j:mpp){
                    if(j.second==t[i]){
                        return false;
                    }
                }
                mpp[s[i]]=t[i];
                
            }
            else{
                if(it->second!=t[i]){
                    return false;
                }

            }
        }
        return true;


    }
};