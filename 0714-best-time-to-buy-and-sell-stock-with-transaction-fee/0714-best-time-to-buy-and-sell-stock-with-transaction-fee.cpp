class Solution {
public:
    int solve(vector<int>& prices, int indx,int buy,int fee,vector<vector<int>>& dp){
        if(indx==prices.size()) return dp[indx][buy] = 0;
        if(dp[indx][buy]!=-1) return dp[indx][buy];
        int profit =0;
        if(buy){
            profit = max(-prices[indx] + solve(prices,indx+1,0,fee,dp), 0 + solve(prices,indx+1,1,fee,dp));
        }
        else{
            profit = max(prices[indx]-fee+ solve(prices,indx+1,1,fee,dp), 0 + solve(prices,indx+1,0,fee,dp));
        }
        return dp[indx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,1,fee,dp);
        
    }
};