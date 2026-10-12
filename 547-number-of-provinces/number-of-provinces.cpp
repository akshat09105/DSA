class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adjLis[]){
        vis[node]=1;
        for(auto it:adjLis[node]){
            if(vis[it]!=1){
                dfs(it,vis,adjLis);
            }
        }
    }
    void bfs(int node,vector<int>&vis,vector<int>adjLis[]){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int num=q.front();
            q.pop();
            for(auto it:adjLis[num]){
                if(vis[it]!=1){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adjLis[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1&&i!=j){
                    adjLis[i].push_back(j);
                    adjLis[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                cnt++;
                bfs(i,vis,adjLis);
            }
        }
        return cnt;
    }
};