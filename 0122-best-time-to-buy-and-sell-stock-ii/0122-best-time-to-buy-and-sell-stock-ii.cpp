class Solution {
    int profit=0;
public:
    int solve(vector<int>& prices, int indx,int buy,vector<vector<int>>& dp){
        if(indx==prices.size()) return dp[indx][buy] = 0;
        if(dp[indx][buy]!=-1) return dp[indx][buy];
        if(buy){
            profit = max(-prices[indx] + solve(prices,indx+1,0,dp), 0 + solve(prices,indx+1,1,dp));
        }
        else{
            profit = max(prices[indx]+ solve(prices,indx+1,1,dp), 0 + solve(prices,indx+1,0,dp));
        }
        return dp[indx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
        
        
    }
};