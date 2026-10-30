class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        if(st.find(beginWord)!=st.end()){
            st.erase(beginWord);
        }
        while(!q.empty()){
            string s=q.front().first;
            int step=q.front().second;
            q.pop();
            if(s==endWord)return step;
            for(int i=0;i<s.size();i++){
                string original=s;
                for(char c='a';c<='z';c++){
                    s[i]=c;
                    if(st.find(s)!=st.end()){
                        q.push({s,step+1});
                        st.erase(s);
                    }
                    s=original;
                }
            }
        }
        return 0;
    }
};