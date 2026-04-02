class Solution {
public:
    int M = 1e9+7;
    vector<vector<pair<long long,long long>>> dp;
    vector<vector<bool>> vis;
    pair<long long, long long> solve(vector<vector<int>>& grid, int row, int col){
        if(row== grid.size()-1 && col == grid[0].size()-1) return {grid[grid.size()-1][grid[0].size()-1],grid[grid.size()-1][grid[0].size()-1]};
        else if (row== grid.size() || col == grid[0].size()) return {LLONG_MIN,LLONG_MAX};
        if(vis[row][col]) return dp[row][col];


        pair<long long, long long> right = solve(grid,row,col+1);
        pair<long long, long long> left = solve(grid,row+1,col);
        long long maxi =LLONG_MIN;
        long long mini = LLONG_MAX;
        if(right.first != LLONG_MIN){
            long long a = 1LL*grid[row][col]*right.first;
            long long b = 1LL*grid[row][col]*right.second;
            maxi =max(maxi,max(a,b));
            mini = min(mini,min(a,b));
        }
        if(left.first != LLONG_MIN){
            long long a = 1LL*grid[row][col]*left.first;
            long long b = 1LL*grid[row][col]*left.second;
            maxi =max(maxi,max(a,b));
            mini = min(mini,min(a,b));
        }
        vis[row][col] =1;
        return dp[row][col] = {maxi,mini};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        dp.resize(grid.size()+1,vector<pair<long long, long long>>(grid[0].size()+1));
        vis.resize(grid.size()+1,vector<bool>(grid[0].size()+1));
        pair<long long, long long> ans = solve(grid,0,0);
        if(ans.first<0) return -1;
        else return int(ans.first%M);
        
    }
};