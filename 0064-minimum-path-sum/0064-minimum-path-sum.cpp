class Solution {
public:
    int sol(int i, int j,vector<vector<int>>& dp,vector<vector<int>>& grid){
        int top=INT_MAX;
        int bottom=INT_MAX;
        int mini=0;
        if(i==0 && j==0) return grid[i][j];
        else if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if (i>0)  top = sol(i-1,j,dp,grid) + grid[i][j];
        if(j>0)  bottom = sol(i,j-1,dp,grid) + grid[i][j];
        mini+= min(top,bottom);
        return dp[i][j] = mini;

    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        return sol(grid.size()-1,grid[0].size()-1,dp,grid);
        
    }
};