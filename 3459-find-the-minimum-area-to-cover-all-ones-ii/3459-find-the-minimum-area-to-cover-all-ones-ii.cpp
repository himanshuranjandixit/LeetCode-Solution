class Solution {
public:
    int minArea(vector<vector<int>>& grid, int startrow, int endrow, int startcol, int endcol){
        int area;
        int n = grid.size();
        int m = grid[0].size();
        int minx=n;
        int miny =m;
        int maxx=0;
        int maxy =0;
        for(int i=startrow;i<=endrow;i++){
            for(int j=startcol;j<=endcol;j++){
                if(grid[i][j]==1){
                    minx =min(minx,i);
                    miny = min(miny,j);
                    maxx=max(maxx,i);
                    maxy=max(maxy,j);
                }
            }
        }
        if (minx > maxx || miny > maxy) return 1e7;
        return (maxx-minx+1)*(maxy-miny+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=m*n;
        //case 1

        for(int rowsplit = 0 ; rowsplit < n-1 ; rowsplit++){
            for(int colsplit = 0 ; colsplit < m-1 ; colsplit++){
                int top = minArea(grid,0,rowsplit,0,m-1);
                int bottomleft = minArea(grid,rowsplit+1,n-1,0,colsplit);
                int bottomright = minArea(grid,rowsplit+1,n-1,colsplit+1,m-1);
                ans=min(ans,top+bottomleft+bottomright);
                int topleft = minArea(grid,0,rowsplit,0,colsplit);
                int topright = minArea(grid,0,rowsplit,colsplit+1,m-1);
                int bottom = minArea(grid,rowsplit+1,n-1,0,m-1);
                ans=min(ans,topleft+topright+bottom);
                int lefttop = minArea(grid,0,rowsplit,0,colsplit);
                int leftbottom = minArea(grid,rowsplit+1,n-1,0,colsplit);
                int right = minArea(grid,0,n-1,colsplit+1,m-1);
                ans=min(ans,lefttop+leftbottom+right);
                int left = minArea(grid,0,n-1,0,colsplit);
                int righttop = minArea(grid,0,rowsplit,colsplit+1,m-1);
                int rightbottom = minArea(grid,rowsplit+1,n-1,colsplit+1,m-1);
                ans=min(ans,left+righttop+rightbottom);
            }
        }
        for(int colsplit1 =0 ; colsplit1 < m-2 ; colsplit1++){
            for(int colsplit2 =colsplit1+1 ; colsplit2<m-1;colsplit2++){
                int left = minArea(grid,0,n-1,0,colsplit1);
                int mid = minArea(grid,0,n-1,colsplit1+1,colsplit2);
                int right = minArea(grid,0,n-1,colsplit2+1,m-1);
                ans=min(ans,left+mid+right);
            }
        }
        for(int rowsplit1 = 0; rowsplit1 < n-2; rowsplit1++){
            for(int rowsplit2 = rowsplit1+1; rowsplit2 < n-1; rowsplit2++){
                int top    = minArea(grid, 0, rowsplit1, 0, m-1);
                int middle = minArea(grid, rowsplit1+1, rowsplit2, 0, m-1);
                int bottom = minArea(grid, rowsplit2+1, n-1, 0, m-1);
                ans = min(ans, top + middle + bottom);
            }
        }
        return ans;

        
    }
};