class Solution {
public:
    long long solve(int n , int limit,int num, int step, vector<vector<long long>>& dp){
        if(dp[num][step]!=-1) return dp[num][step];
        if(step==3 && num==0){
            return 1;
        }
        if(step>3) return 0;
        if(step==3) return 0;
        long long ans=0;
        for(int i=0;i<=min(num,limit);i++){
            ans+=solve(n,limit,num-i,step+1,dp);
        }
        return dp[num][step]=ans;
    }
    long long distributeCandies(int n, int limit) {
        // vector<vector<long long>>dp(n+1,vector<long long>(4,-1));
        // return solve(n,limit,n,0,dp);
        long long ans=0;
        for(int i=0;i<=min(limit,n);i++){
            if((n-i)>limit*2) continue;
            ans+=min(n-i,limit)-max(0,n-i-limit)+1;
        }
        return ans;

        
    }
};