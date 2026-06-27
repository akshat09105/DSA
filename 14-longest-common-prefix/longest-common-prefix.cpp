class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();int common=0;
        if(n==1){
            return strs[0];
        }
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<n;j++){
                if(strs[0][i]!=strs[j][i]){

                    return strs[0].substr(0,i);
                }
            }
            if(i==strs[0].size()-1){
                return strs[0];
            }
        }
        return "";

    }
};