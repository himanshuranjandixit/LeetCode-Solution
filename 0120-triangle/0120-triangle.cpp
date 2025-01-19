class Solution {
public:
    int sol(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==triangle.size()-1) return triangle[i][j];
        int ans=0;
        if(dp[i][j] !=-1) return dp[i][j];
        int ith =sol(i+1,j,triangle,dp) +triangle[i][j];
        int ipth=sol(i+1,j+1,triangle,dp) + triangle[i][j];
        return dp[i][j]=min(ith,ipth);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return sol(0,0,triangle,dp);
        
    }
};