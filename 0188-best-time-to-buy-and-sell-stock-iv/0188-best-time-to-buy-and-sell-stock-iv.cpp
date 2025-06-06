class Solution {
public:
     int solve(vector<int>& prices, int indx ,int buy, int count,int maxsell,vector<vector<vector<int>>>& dp){
        if(indx==prices.size() || count==maxsell) return dp[indx][buy][count]= 0;
        if(dp[indx][buy][count]!=-1) return dp[indx][buy][count];
        long profit = 0;
        if(buy){
            profit = max(-prices[indx] + solve(prices,indx+1,0,count,maxsell,dp), solve(prices,indx+1,1,count,maxsell,dp));
        }
        else{
            profit = max(prices[indx] + solve(prices,indx+1,1,count+1,maxsell,dp), solve(prices,indx+1,0,count,maxsell,dp));
        }
        return dp[indx][buy][count] = int(profit);

    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,1,0,k,dp);
        
        
    }
};