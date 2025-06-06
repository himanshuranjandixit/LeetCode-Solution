class Solution {
public:
    int solve(vector<int>& num, int indx,int previndx,int prev,vector<vector<int>>& dp){
        if(indx==num.size()) return dp[indx][previndx+1] = 0;
        if(dp[indx][previndx+1]!=-1) return dp[indx][previndx+1];
        int ans=0;
        int ans1=solve(num,indx+1,previndx,prev,dp);
        if(num[indx]>prev) ans=1+solve(num,indx+1,indx,num[indx],dp);
        return dp[indx][previndx+1] = max(ans,ans1);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,-1e5,dp);
    }
};