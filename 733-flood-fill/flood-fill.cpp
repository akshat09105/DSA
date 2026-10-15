class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>&ans, int sr, int sc, int color,int inicolor,int delRow[],int delCol[],int n,int m){
        ans[sr][sc]=color;
        for(int i=0;i<4;i++){
            int nrow=sr+delRow[i];
            int ncol=sc+delCol[i];
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&image[nrow][ncol]==inicolor&&ans[nrow][ncol]!=color)
            dfs(image,ans,nrow,ncol,color,inicolor,delRow,delCol,n,m);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int inicolor=image[sr][sc];
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        vector<vector<int>>ans=image;
        dfs(image,ans,sr,sc,color,inicolor,delRow,delCol,n,m);  
        return ans;
    }
};