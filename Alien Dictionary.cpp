class Solution {
  public:
    string bfs_topo(vector<int>adj[],int unique,vector<int>&present){
        vector<int>indegree(unique,0);
        for(int i=0;i<unique;i++){
            for(int it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<unique;i++){
            if(present[i]==1&&indegree[i]==0){
                q.push(i);
            }
        }
        string s="";
        while(!q.empty()){
            int node=q.front();
            q.pop();
            s+=(node+'a');
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            
        }
        return s;
        
    }
    string findOrder(vector<string> &words) {
        // code here
        //feels like topo sort...thinking of implementing it
        vector<int>present(26,0);
        for(int i=0;i<words.size();i++){
            for(auto it:words[i]){
                present[it-'a']=1;
            }
        }
        int unique=0;
        for(int i=0;i<26;i++){
            if(present[i])unique++;
        }
        int n=words.size();
        vector<int>adj[26];
        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            for(int ptr=0;ptr<len;ptr++){
                if(s1[ptr]!=s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }

        //now graph is created topo sort needs to applied
        string ans=bfs_topo(adj,26,present);
        if(ans.size()==unique)return ans;
        return "";
        
        
        
    }
};
