class Solution {
public:
    vector<vector<vector<long long>>>dp;
    vector<vector<vector<bool>>>vis;
    long long solve(vector<vector<int>>& coins, int row, int col, int neutralizer){
        int n = coins.size();
        int m = coins[0].size();
        if(neutralizer<0) return INT_MIN;
        if(row==n-1 && col==m-1){
            if(coins[row][col]>0) return coins[row][col];
            if(neutralizer>0) return 0;
            return coins[row][col];
        }
        else if(row == n || col == m) return INT_MIN;
        if(vis[row][col][neutralizer]) return dp[row][col][neutralizer];
        long long right = 0;
        long long down = 0;
        if(coins[row][col] <0) right = max(coins[row][col] + solve(coins,row,col+1,neutralizer),solve(coins,row,col+1,neutralizer-1));
        else right = coins[row][col] + solve(coins,row,col+1,neutralizer);
        if(coins[row][col] <0) down = max(coins[row][col] + solve(coins,row+1,col,neutralizer),solve(coins,row+1,col,neutralizer-1));
        else down = coins[row][col] + solve(coins,row+1,col,neutralizer);
        vis[row][col][neutralizer] = true;
        return dp[row][col][neutralizer] =  max(right,down);

    }
    int maximumAmount(vector<vector<int>>& coins) {
        dp.resize(coins.size()+1,vector<vector<long long>>(coins[0].size()+1,vector<long long>(3)));
        vis.resize(coins.size()+1,vector<vector<bool>>(coins[0].size()+1,vector<bool>(3)));
        return (int)solve(coins,0,0,2);

        
    }
};