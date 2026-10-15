class Solution {
public:
    void bfs(int sr, int sc,vector<vector<int>>& image,int m,int n,vector<vector<int>>&vis,int curr,int color){
        int node=image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            image[x][y]=color;
            for(int delX=-1;delX<=1;delX++){
                int nx=x+delX;
                if(nx>=0&&nx<m&&image[nx][y]==curr&&vis[nx][y]!=1){
                    q.push({nx,y});
                    vis[nx][y]=1;
                }
            }
            for(int delY=-1;delY<=1;delY++){
                int ny=y+delY;
                if(ny>=0&&ny<n&&image[x][ny]==curr&&vis[x][ny]!=1){
                    q.push({x,ny});
                    vis[x][ny]=1;
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();int n=image[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int curr=image[sr][sc];
        bfs(sr,sc,image,m,n,vis,curr,color);
        return image;
    }
};