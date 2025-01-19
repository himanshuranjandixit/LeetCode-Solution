class Solution {
public:
    int sol(int i, int j,int n, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i==n-1) return matrix[i][j];
        if(j<0 || j>=n) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=INT_MAX,right = INT_MAX,below=INT_MAX;
        if(j>0) left = sol(i+1,j-1,n,matrix,dp) + matrix[i][j];
        below = sol(i+1,j,n,matrix,dp) + matrix[i][j];
        if(j<n-1) right = sol(i+1,j+1,n,matrix,dp) + matrix[i][j];
        return dp[i][j]=min(left,min(right,below));

       

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            ans=min(ans,sol(0,i,n,matrix,dp));
        }
        return ans;
        
    }
};