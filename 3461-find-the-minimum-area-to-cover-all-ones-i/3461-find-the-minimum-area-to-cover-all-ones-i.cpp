class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minx=grid.size();
        int miny =grid[0].size();
        int maxx = 0;
        int maxy = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    minx = min(minx,i);
                    miny = min(miny,j);
                    maxx = max(maxx,i);
                    maxy = max(maxy,j);
                }
            }
        }
        return (maxx-minx+1) * (maxy-miny+1);
        
    }
};