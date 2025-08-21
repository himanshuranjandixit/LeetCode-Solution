class Solution {
public:
    int solve(int row, int col, vector<vector<char>>& matrix,vector<vector<int>>& dp){
        if(row>=matrix.size() || col>=matrix[0].size()) return 0;
        if(matrix[row][col]=='0') return 0;
        if(dp[row][col]!=-1) return dp[row][col]; 
        int right = solve(row,col+1,matrix,dp);
        int bottom = solve(row+1,col,matrix,dp);
        int diag = solve(row+1,col+1,matrix,dp);
        return dp[row][col] = 1+ min(right,min(bottom,diag));
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans =0;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    ans=max(ans,solve(i,j,matrix,dp));
                }
            }
        }
        return ans*ans;
        
    }
};