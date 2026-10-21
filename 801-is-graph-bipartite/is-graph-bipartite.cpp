class Solution {
public:
    bool dfs(int src,int col,int color[],vector<vector<int>>& graph){
        color[src]=col;
        for(auto it:graph[src]){
            if(color[it]==-1){
                if(!dfs(it,!col,color,graph))return false;
            }
            else if(color[it]==col)return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        int color[V];//0 based indexing graph
        for(int i=0;i<V;i++){
            color[i]=-1;
        }
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph))return false;
            }
        }
        return true;
    }
};