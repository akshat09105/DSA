class Solution{
public:
    vector<vector<string>> findSequences(string s, string e,
                                         vector<string> &words) {
        unordered_set<string>st(words.begin(),words.end());
        queue<vector<string>>q;
        vector<string>levelOrder;
        q.push({s});
        levelOrder.push_back(s);
        int level=0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec=q.front();
            q.pop();
            if(vec.size()>level){
                level++;
                for(auto it:levelOrder){
                    st.erase(it);
                    
                }
                levelOrder.clear();
            }
            string word=vec.back();
            if(word==e){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.find(word)!=st.end()){
                        vec.push_back(word);
                        levelOrder.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;
        
    }
};
