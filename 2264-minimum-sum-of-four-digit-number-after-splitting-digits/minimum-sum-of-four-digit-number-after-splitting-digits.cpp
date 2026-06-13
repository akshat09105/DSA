class Solution {
public:
    int minimumSum(int num) {
        vector<int>ans;
        string s=to_string(num);
        for(auto c:s){
            ans.push_back(c-'0');
        }
        sort(ans.begin(),ans.end());
        int x=ans[0]*10+ans[3]+ans[1]*10+ans[2];
        return x;
    }
};