class Solution {
public:
    int n;int m;
    bool isvalid(int i, int j){
        if(i>=0 &&i<n && j>=0&& j<m) return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>>v;
        n = isWater.size();
        m =isWater[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                isWater[i][j] =isWater[i][j]^1;
                if(isWater[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int val = q.front().second;
            isWater[row][col] =val;
            q.pop();
            int drow[4] ={0,-1,0,1};
            int dcol[4] ={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(isvalid(nrow,ncol) && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},val+1});

                }
            }
        }
        return isWater;


        
    }
};