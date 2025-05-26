class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>dist(grid.size(),vector<int>(grid[0].size(),1e9));
        if(grid[0][0]==1) return -1; 
        dist[0][0]=1;
        set<pair<int,pair<int,int>>>pq;
        pq.insert(make_pair(1,make_pair(0,0)));

        while(!pq.empty()){
            int row = pq.begin()->second.first;
            int col = pq.begin()->second.second;
            pq.erase(pq.begin());
            int drow[]={0,-1,-1,-1,0,1,1,1};
            int dcol[]={1,1,0,-1,-1,-1,0,1};
            for(int i=0;i<8;i++){
                if(row+drow[i]>=0 && row+drow[i]<grid.size() && col+dcol[i]>=0 && col+dcol[i]<grid[0].size()){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(grid[nrow][ncol]==0){
                        if(dist[row][col]+1<dist[nrow][ncol]){
                            if(dist[nrow][ncol]!=1e9) pq.erase(make_pair(dist[nrow][ncol],make_pair(nrow,ncol)));
                            dist[nrow][ncol]=dist[row][col]+1;
                            pq.insert(make_pair(dist[nrow][ncol],make_pair(nrow,ncol)));
                        }
                    }

                }
            }
        }
        if(dist[grid.size()-1][grid[0].size()-1]==1e9) return -1;
        return dist[grid.size()-1][grid[0].size()-1];

        
    }
};