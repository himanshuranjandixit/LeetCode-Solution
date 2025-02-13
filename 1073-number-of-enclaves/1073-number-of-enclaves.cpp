class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                if(i==grid.size()-1 && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                if(j==0 && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
                if(j==grid[0].size()-1 && grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            grid[i][j]=0;
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int row=i+drow[k];
                int col=j+dcol[k];
                if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && vis[row][col]==0 && grid[row][col]==1){
                    q.push({row,col});
                    vis[row][col]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) count++;
            }
        }
        return count;
        
    }
};