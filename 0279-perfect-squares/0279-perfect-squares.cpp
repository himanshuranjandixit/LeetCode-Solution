class Solution {
public:
    long long solve(int n,vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        long long ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            long long count = 1+solve(n-i*i,dp);
            ans=min(ans,count);
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return int(solve(n,dp));
       
    }
};