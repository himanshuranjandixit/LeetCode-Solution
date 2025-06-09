class Solution {
public:
    int solve(vector<int>& nums, int i, int j,vector<vector<int>>& dp){
        if(i>j) return dp[i][j] = 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int coins = INT_MIN;
        for(int indx=i;indx<=j;indx++){
            int cost = nums[i-1]*nums[indx]*nums[j+1] + solve(nums,i,indx-1,dp) + solve(nums,indx+1,j,dp);
            coins=max(coins,cost);
        }
        return dp[i][j] = coins;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(nums,1,nums.size()-2,dp);
        
    }
};