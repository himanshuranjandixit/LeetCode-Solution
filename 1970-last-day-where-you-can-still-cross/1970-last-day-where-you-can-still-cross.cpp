class Solution {
    using P = pair<int,int>;
public:
    map<P,P> par;
    int row,col;
    vector<vector<int>>grid;

    P find(P u){
        if(par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void Union(P u, P v){
        P pu = find(u);
        P pv = find(v);
        if(pu != pv){
            par[pu] = pv;
        }
    }

    bool valid(int r, int c){
        return r >= 0 && r < row && c >= 0 && c < col;
    }

    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        row = r;
        col = c;
        grid.assign(row,vector<int>(col,0));

        P top = {-1, -1};
        P bottom = {-2, -2};

        par[top] = top;
        par[bottom] = bottom;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i = cells.size() - 1; i >= 0; i--){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
            par[{x,y}] = {x,y};

            for(auto &d : dirs){
                int nx = x + d[0];
                int ny = y + d[1];
                if(valid(nx, ny) && grid[nx][ny]){
                    Union({x,y}, {nx,ny});
                }
            }
            if(x == 0) Union({x,y}, top);
            if(x == row - 1) Union({x,y}, bottom);
            if(find(top) == find(bottom)){
                return i;
            }
        }
        return 0;
    }
};
