class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        // Fix 3 & 4: Min-heap + long long for distance
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> q; // {dis, node}

        vector<long long> dis(n, LLONG_MAX); // Fix 4: LLONG_MAX instead of 1e9
        vector<long long> ways(n, 0);
        long long mod = 1e9 + 7;

        q.push({0, 0});
        dis[0] = 0;
        ways[0] = 1;

        while (!q.empty()) {
            auto it = q.top(); // .top() for priority_queue
            long long dist = it.first;
            int node = it.second;
            q.pop();

            if (dist > dis[node]) continue;

            for (auto iter : adj[node]) {
                int adjNode = iter.first;
                long long edW = iter.second;

                // Fix 1: Compare with dis[adjNode], not dis[node]
                if (dist + edW < dis[adjNode]) {
                    dis[adjNode] = dist + edW;
                    ways[adjNode] = ways[node];
                    q.push({dis[adjNode], adjNode});
                }
                // Fix 1 & 2: Check == dis[adjNode] and add ways[node]
                else if (dist + edW == dis[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] ;
    }
};