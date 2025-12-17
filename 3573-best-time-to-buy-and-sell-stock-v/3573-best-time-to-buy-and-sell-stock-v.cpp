class Solution {
    int n;
public:
    long long solve(vector<int>& prices, int indx, int k, int marzi,vector<vector<vector<__int128>>>& dp){
        if(indx == n || k<=0){
            if(marzi==0) return 0;
            else return INT_MIN;
        }
        if(dp[indx][k][marzi] !=-1) return dp[indx][k][marzi];
        long long ans = INT_MIN;
        if(marzi ==0){
            long long int not_take = solve(prices,indx+1,k,0, dp);
            long long int buy = solve(prices,indx+1,k,1,dp)-prices[indx];
            long long int sell = solve(prices,indx+1,k,2,dp)+ prices[indx];
            ans =max(not_take,max(buy,sell));
        }
        else if(marzi==1){
            long long int sell = solve(prices,indx+1,k-1,0,dp) + prices[indx];
            long long int not_take = solve(prices,indx+1,k,1,dp);
            ans = max(not_take,sell);
        }
        else{
            long long int  buy =solve(prices,indx+1,k-1,0,dp) - prices[indx];
            long long int not_take = solve(prices,indx+1,k,2,dp);
            ans = max(not_take,buy);
        }
        return dp[indx][k][marzi] = ans;

        
    }
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<vector<__int128>>>dp (n+1, vector<vector<__int128>>(k+1,vector<__int128>(3,-1)));
        return solve(prices,0,k,0,dp);
        
        
    }
};