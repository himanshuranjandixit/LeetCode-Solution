class Solution {
public:
    int solve(vector<int>& job, int indx, int d, vector<vector<int>>& dp){
        if(indx==job.size() ){
            if(d==0) return  0 ;
            else return INT_MAX;

        }
        if(d==0) return INT_MAX;
        if(dp[indx][d]!=-1) return dp[indx][d];
        int res =INT_MAX;
        int maxval=0;
        for(int i=indx;i<job.size()-d+1;i++){
            maxval=max(maxval,job[i]);
            int val = solve(job,i+1,d-1,dp);
            if(val!=INT_MAX) res =min(res, val+maxval);
        }
        return dp[indx][d] =  res;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<int>day;
        vector<vector<int>>dp(jobDifficulty.size()+1,vector<int>(d+1,-1));
        int ans = solve(jobDifficulty, 0, d,dp);
        if(ans==INT_MAX) return -1;
        return ans;

        
    }
};