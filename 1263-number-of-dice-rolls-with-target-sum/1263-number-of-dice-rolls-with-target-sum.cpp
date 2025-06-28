class Solution {
public:
    int m = 1e9 +7;
    int solve(int n, int k , int target,vector<vector<int>>& dp){
        if(n==0 && target!=0) return 0;
        if(target==0 && n==0) return 1;
        if(dp[n][target]!=-1) return dp[n][target];
        int take = 0;
        for(int i=1;i<=k;i++){
            if(target-i>=0) take = (take + solve(n-1,k,target-i,dp)) %m;
            else break;
        }
        return dp[n][target] = take;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(n*k<target) return 0;
        vector<vector<int>>dp(31,vector<int>(1000,-1));
        return solve(n,k,target,dp);

        
    }
};