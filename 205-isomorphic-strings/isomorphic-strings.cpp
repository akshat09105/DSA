class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mpp1;
        unordered_map<char,char>mpp2;
        int n=s.size();
        for(int i=0;i<n;i++){
            auto it1=mpp1.find(s[i]);
            auto it2=mpp2.find(t[i]);
            if(it1==mpp1.end()&& it2==mpp2.end()){
                mpp1[s[i]]=t[i];
                mpp2[t[i]]=s[i];
                
            }
            else if(it1==mpp1.end() && it2!=mpp1.end()){
                return false;
            }
            else if(it1!=mpp1.end() && it2==mpp1.end()){
                return false;
            }
            else{
                if(it1->second!=t[i]||it2->second!=s[i]){
                    return false;
                }

            }
        }
        return true;


    }
};