class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>check(26,0);
        for(int i=0;i<text.size();i++){
            check[text[i]-'a']++;
        }
        vector<int>ball(26,0);
        string s="balloon";
        for(int i=0;i<s.size();i++){
            ball[s[i]-'a']++;
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            if(ball[i]!=0){
                ans=min(ans,(int)check[i]/ball[i]);
            }
        }
        if(ans==INT_MAX)return 0;
        return ans;

    }
};