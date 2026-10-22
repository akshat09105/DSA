class Solution {
public:
    bool dfs(int numCourses,vector<int> &vis,vector<int>&pathVis,vector<int>adj[]){
        vis[numCourses]=1;
        pathVis[numCourses]=1;
        for(auto it:adj[numCourses]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj))return true;
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[numCourses]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true)return false;
            }
        }
    
        return true;
    }
};