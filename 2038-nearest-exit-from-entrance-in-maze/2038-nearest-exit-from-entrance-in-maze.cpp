class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int startrow = entrance[0];
        int startcol = entrance[1];
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{startrow,startcol}});
        bool start =true;
        visited[startrow][startcol] =1;
        while(!pq.empty()){
            int currRow = pq.front().second.first;
            int currCol = pq.front().second.second;
            int step = pq.front().first;
            pq.pop();
            if(maze[currRow][currCol] =='.' && (currRow==0 || currRow==n-1 ||currCol ==0 || currCol == m-1) && !start) return step;
            start = false;
            int drow[4] ={0,-1,0,1};
            int dcol[4]= {1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow = currRow + drow[i];
                int ncol = currCol + dcol[i];
                if(nrow >=0 && nrow < n && ncol>=0 && ncol <m && !visited[nrow][ncol] && maze[nrow][ncol]=='.'){
                    visited[nrow][ncol]=1;
                    pq.push({step+1,{nrow,ncol}});
                }
            }

        }
        return -1;
        
    }
};