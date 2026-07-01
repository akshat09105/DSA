class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;   
        }
        vector<pair<char,int>>ans(mpp.begin(),mpp.end());
        sort(ans.begin(),ans.end(),[](const auto &a,const auto &b){
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        string answer;
        for(int i=0;i<ans.size();i++){
            int x=ans[i].second;
            while(x>0){
                answer.push_back(ans[i].first);
                x--;
            }
        }
        return answer;

    }
};