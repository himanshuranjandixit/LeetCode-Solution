class Solution {
public:
    bool solve(vector<int>& nums, int indx,vector<int>& dp){
        if(indx>=nums.size()-1) return dp[indx]=true;
        if(dp[indx]!=-1) return dp[indx];
        for(int i=1;i<=nums[indx];i++){
            if(indx+i<nums.size() && solve(nums,indx+i,dp)) return dp[indx]=true;
        } 
        return dp[indx]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+nums[nums.size()-1]+1,-1);
        return solve(nums,0,dp);
        
    }
};