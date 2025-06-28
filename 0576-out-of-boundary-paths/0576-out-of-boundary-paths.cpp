class Solution {
public:
int M = 1e9+7;
int dp[51][51][51];
    int solve(int m, int n , int maxmove, int row, int col){
        if(row <0 || row>m-1 || col<0 || col>n-1) return 1;
        if(maxmove==0) return 0 ;
        if(dp[row][col][maxmove]!=-1) return dp[row][col][maxmove];
        int drow[4] = {0,-1,0,1};
        int dcol[4] = {1,0,-1,0};
        int ans=0;
        for(int i=0;i<4;i++){
            int nrow = drow[i] + row;
            int ncol = dcol[i] + col;
            ans = (ans+ solve(m,n,maxmove-1,nrow,ncol))%M;
        }
        return dp[row][col][maxmove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,maxMove,startRow, startColumn);
    }
};