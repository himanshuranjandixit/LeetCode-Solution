class Solution {
public:
    vector<vector<int>>dir = {{1,1},{1,-1},{-1,-1},{-1,1}};
    int solve(vector<vector<int>>& grid, int row, int col , int d, bool turn,int target){
        int drow = row + dir[d][0];
        int dcol = col + dir[d][1];
        if(dcol<0 || drow<0 || drow>=grid.size() || dcol>=grid[0].size() || grid[drow][dcol]!=target) return 0;
        int res= 1 + solve(grid,drow,dcol,d,turn,target== 2 ? 0 : 2);
        int ans=0; 
        ans=max(ans,res);
        if(turn){
            int resturn = max(res,1+solve(grid,drow,dcol,d==3?0:d+1,false,target==2?0:2));
            ans=max(ans,resturn);
        }
        return ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = 0; 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    for(int d =0;d<4;d++){
                        bool turn = true;
                        ans = max(ans,1+solve(grid,i,j,d,turn,2));
                    }
                }
            }
        }
        return ans;
    }
};