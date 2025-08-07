class Solution {
public:
    int n;
    vector<vector<int>> grid;
    int h1(int i, int j , vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || i >= n || j > i) return INT_MIN; 
        if (i == n - 1 && j == n - 1) return grid[i][j]; 
        if(dp[i][j] != -1) return dp[i][j];

        int maxx = 0;

        maxx = max(maxx, grid[i][j] + h1(i - 1, j + 1 , dp));  
        maxx = max(maxx, grid[i][j] + h1(i , j + 1 , dp));
        maxx = max(maxx, grid[i][j] + h1(i + 1, j + 1 , dp)); 

        return dp[i][j] = maxx;
    }
    int h2(int i , int j , vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= n || j >= n || i > j) return INT_MIN;
        if(i == n - 1 && j == n - 1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int maxx = 0;

        maxx = max(maxx, grid[i][j] + h2(i + 1, j - 1 , dp));  
        maxx = max(maxx, grid[i][j] + h2(i + 1, j , dp));
        maxx = max(maxx, grid[i][j] + h2(i + 1, j + 1 , dp)); 

        return dp[i][j] = maxx;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        grid = fruits;
        int a = 0;
        for(int i=0;i<n;i++){
            a+=grid[i][i];
            grid[i][i] =0;
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1 , -1));
        int b = h1(n - 1 , 0 , dp);
        dp.assign(n, vector<int>(n, -1));
        int c = h2(0 , n - 1 , dp);
        return a + b + c;
    }
};