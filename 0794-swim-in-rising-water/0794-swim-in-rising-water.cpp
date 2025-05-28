class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size(),1e8));
        v[0][0]=grid[0][0];
        while(!pq.empty()){
            int time =pq.top().first;
            int row=pq.top().second.first;
            int col = pq.top().second.second;
            if(row==grid.size()-1 && col == grid[0].size()-1) return time;
            pq.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol < grid[0].size()){
                    int ntime = max(time,grid[nrow][ncol]);
                    if(ntime<v[nrow][ncol]){
                        v[nrow][ncol]=ntime;
                        pq.push({ntime,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;

        
    }
};