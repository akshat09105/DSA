class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<int>& pathVis,
             stack<int>& st, vector<int> adj[]) {

        vis[src] = 1;
        pathVis[src] = 1;

        for (auto it : adj[src]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, st, adj))
                    return true;
            }
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[src] = 0;
        st.push(src);
        return false;
    }

    vector<int> findOrder(int numCourses,
                          vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        stack<int> st;
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, st, adj))
                    return {};
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};