class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        unordered_map<char,char>mpp1;
        unordered_map<char,char>mpp2;
        for(int i=0;i<n;i++){
            auto it1=mpp1.find(s[i]);
            auto it2=mpp2.find(t[i]);
            if(it1==mpp1.end() && it2==mpp2.end()){
                mpp1[s[i]]=t[i];//a->b
                mpp2[t[i]]=s[i];//b->a
            
            }
            else if(it1==mpp1.end() && it2!=mpp2.end()){//c->b will be invalid
                return false;  //as b already has one to one relation with therefore present in mpp2
            }
            else if(it1!=mpp1.end() && it2==mpp2.end()){
                return false;
            }
            else{
                if(it1->second==t[i] && it2->second==s[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;


    }
};