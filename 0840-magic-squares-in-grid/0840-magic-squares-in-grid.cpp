class Solution {
public:
    bool check(vector<vector<int>>&grid,int i, int j){
        unordered_set<int>st;
        for(int row=i;row<i+3;row++){
            for(int col=j;col<j+3;col++){
                if(grid[row][col]>9 || grid[row][col]<1) return false;
                st.insert(grid[row][col]);
            }
        }
        if(st.size()!=9) return false;
        int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2];

        if(sum != grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2]) return false;
        if(sum != grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]) return false;
        if(sum != grid[i][j] + grid[i+1][j] + grid[i+2][j]) return false;
        if(sum != grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1]) return false;
        if(sum != grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2]) return false;
        if(sum != grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]) return false;
        if(sum != grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size()<3 || grid[0].size()<3) return 0;
        int cnt=0;
        for(int i=0;i<grid.size()-2;i++){
            for(int j=0;j<grid[0].size()-2;j++){
                if(check(grid,i,j)) cnt++;
            }
        }
        return cnt;
        
    }
};