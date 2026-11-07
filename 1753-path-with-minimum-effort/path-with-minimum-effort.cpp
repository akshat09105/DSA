class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //let it be m*n matrix
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>dist(m,(vector<int>(n,1e9)));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==m-1&&y==n-1)return dist[x][y];
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newx<m&&newy>=0&&newy<n){
                    int maxdiff=max(diff,abs(heights[newx][newy]-heights[x][y]));
                    if(maxdiff<dist[newx][newy]){
                        dist[newx][newy]=maxdiff;
                        pq.push({dist[newx][newy],{newx,newy}});
                    }
                }
            }
        }
        return -1;
        
    }
};