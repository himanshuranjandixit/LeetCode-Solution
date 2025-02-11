class Solution {
public:
    int orangesRotting(vector<vector<int>>& gridd) {
        // bool find=true;
        // int count=0;
        // vector<vector<int>>grid(gridd.size()+1,vector<int>(gridd[0].size()+1,-1));
        // for(int i=0;i<gridd.size();i++){
        //     for(int j=0;j<gridd[0].size();j++){
        //         grid[i][j]=gridd[i][j];
        //     }
        // }
        // while(find){
        //     count++;
        //     find=false;
        //     vector<pair<int,int>>p;
        //     for(int i=0;i<grid.size();i++){
        //         for(int j=0;j<grid[0].size();j++){
        //             if(i==0 && j==0){
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j+1]==1) p.emplace_back(i,j+1);
        //                     if(grid[i+1][j]==1) p.emplace_back(i+1,j);
        //                 }
        //             }
        //             else if(i==0 && j==grid[0].size()-1){
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j-1]==1) p.emplace_back(i,j-1);
        //                     if(grid[i+1][j]==1) p.emplace_back(i+1,j);
        //                 }
        //             }
        //             else if(i==grid.size()-1 && j==0){
        //                 if(grid[i][j]==2){
        //                     if(grid[i-1][j]==1) p.emplace_back(i-1,j);
        //                     if(grid[i][j+1]==1) p.emplace_back(i,j+1);
        //                 }
        //             }
        //             else if(i==grid.size()-1 && j==grid[0].size()-1){
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j-1]==1) p.emplace_back(i,j-1);
        //                     if(grid[i-1][j]==1) p.emplace_back(i-1,j);
        //                 }
        //             }
        //             else if(i==0){
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j-1]==1) p.emplace_back(i,j-1);
        //                     if(grid[i+1][j]==1) p.emplace_back(i+1,j);
        //                     if(grid[i][j+1]==1) p.emplace_back(i,j+1);
        //                 }
        //             }
        //             else if(j==0){
        //                 if(grid[i][j]==2){
        //                     if(grid[i+1][j]==1) p.emplace_back(i+1,j);
        //                     if(grid[i-1][j]==1) p.emplace_back(i-1,j);
        //                     if(grid[i][j+1]==1) p.emplace_back(i,j+1);
        //                 }
        //             }
        //             else if(i==grid.size()-1){
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j-1]==1) p.emplace_back(i,j-1);
        //                     if(grid[i-1][j]==1) p.emplace_back(i-1,j);
        //                     if(grid[i][j+1]==1) p.emplace_back(i,j+1);
        //                 }
        //             }
        //             else if(j==grid[0].size()-1){
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j-1]==1) p.emplace_back(i,j-1);
        //                     if(grid[i+1][j]==1) p.emplace_back(i+1,j);
        //                     if(grid[i-1][j]==1) p.emplace_back(i-1,j);
        //                 }
        //             }
        //             else{
        //                 if(grid[i][j]==2){
        //                     if(grid[i][j-1]==1) p.emplace_back(i,j-1);
        //                     if(grid[i+1][j]==1) p.emplace_back(i+1,j);
        //                     if(grid[i][j+1]==1) p.emplace_back(i,j+1);
        //                     if(grid[i-1][j]==1) p.emplace_back(i-1,j);
        //                 }
        //             }
        //         }
        //     }
        //     for(auto it : p){
        //         grid[it.first][it.second]=2;
        //         find=true;
        //     }
        // }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(grid[i][j]==1) return -1;
        //     }
        // }
        // return count-1;
        int n=gridd.size();
        int m =gridd[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(gridd[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int tm=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && gridd[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && gridd[i][j]==1) return -1;
            }
        }
        return tm;
    }
};