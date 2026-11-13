class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //floyd warshall algo is clicking in my mind
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++){//via k
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=1e8&&dist[k][j]!=1e8){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        //dist is ready
        int SmallestConnectedCity=INT_MAX;int city;
        for(int j=0;j<n;j++){
            int ConnectedCity=0;
            for(int i=0;i<n;i++){
                if(i!=j&&dist[i][j]<=distanceThreshold){
                    ConnectedCity++;
                } 
            }
            if(ConnectedCity<=SmallestConnectedCity){
                SmallestConnectedCity=ConnectedCity;
                city=j;
            }
        }
        return city;
    }
};