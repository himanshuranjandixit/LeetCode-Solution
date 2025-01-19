class Solution {
public:
    int sol(int i, int j,vector<vector<int>>& dp,vector<vector<int>>grid){
        int top=0;
        int bottom=0;
        if(i==0 && j==0){
            if(grid[0][0]!=1) return 1;
            else return 0;
        }
        // else if((i==0 && j==1)||(i==1 && j==0)) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1) return 0;
        if (i>0)  top += sol(i-1,j,dp,grid);
        if(j>0)  bottom += sol(i,j-1,dp,grid);
        return dp[i][j] = top+bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sol(m-1,n-1,dp,obstacleGrid);

        
    }
};