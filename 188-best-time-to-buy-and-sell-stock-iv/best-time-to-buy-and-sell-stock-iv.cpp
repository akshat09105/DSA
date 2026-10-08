class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int i=0;i<=1;i++){//base*cap
            for(int j=0;j<=k;j++){
                prev[i][j]=0;
            }
        }
        for(int i=0;i<n;i++){
            for(int buy=0;buy<=1;buy++){
                prev[buy][0]=0;
            }
        }
        
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit;
                    if(buy){//buy=1 means you have to buy
                    profit=max(-prices[index]+prev[0][cap],0+prev[1][cap]);
                    }
                    else{
                        profit=max(prices[index]+prev[1][cap-1],0+prev[0][cap]);
                    }
                    curr[buy][cap]=profit;
                }
            }
            prev=curr;
        }
        return prev[1][k];
    }
    
};