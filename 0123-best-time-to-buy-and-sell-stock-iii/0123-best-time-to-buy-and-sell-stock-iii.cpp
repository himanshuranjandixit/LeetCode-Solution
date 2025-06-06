class Solution {
public:
    int solve(vector<int>& prices, int indx ,int buy, int count,vector<vector<vector<int>>>& dp){
        if(indx==prices.size() || count==2) return dp[indx][buy][count]= 0;
        if(dp[indx][buy][count]!=-1) return dp[indx][buy][count];
        long profit = 0;
        if(buy){
            profit = max(-prices[indx] + solve(prices,indx+1,0,count,dp), solve(prices,indx+1,1,count,dp));
        }
        else{
            profit = max(prices[indx] + solve(prices,indx+1,1,count+1,dp), solve(prices,indx+1,0,count,dp));
        }
        return dp[indx][buy][count] = int(profit);

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,0,dp);
        
        
    }
};