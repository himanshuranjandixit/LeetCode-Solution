class Solution {
public:
    int sol(int i, int j,vector<vector<int>>& dp){
        int top=0;
        int bottom=0;
        if(i==0 && j==0) return 0;
        else if((i==0 && j==1)||(i==1 && j==0)) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if (i>0)  top += sol(i-1,j,dp);
        if(j>0)  bottom += sol(i,j-1,dp);
        return dp[i][j] = top+bottom;
    }
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return sol(m-1,n-1,dp);
        
    }
};