class Solution {
public:
    int solve(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int indx=i;indx<=j;indx++){
            int cost = cuts[j+1] - cuts[i-1] + solve(cuts,i,indx-1,dp) + solve(cuts,indx+1,j,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
 
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        sort(cuts.begin(),cuts.end());
        return solve(cuts,1,cuts.size()-2,dp);
        
    }
};