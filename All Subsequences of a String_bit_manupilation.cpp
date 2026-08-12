class Solution {
  public:
    vector<string> powerSet(string &s) {
        // Code here
        //using power set algorithm to solve this problem
        vector<string>ans;
        for(int num=0;num<pow(2,s.size());num++){
            string list;
            for(int i=0;i<s.size();i++){
                if(num&(1<<i)){
                    list+=s[i];
                }
            }
            ans.push_back(list);
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
