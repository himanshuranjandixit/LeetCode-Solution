class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>vis(mat.size(),vector<int>(mat[0].size(),0));
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size(),0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first.first;
            int j= q.front().first.second;
            int step =q.front().second;
            q.pop();
            ans[i][j]=step;
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int row=i+drow[k];
                int col=j+dcol[k];
                if(row>=0 && row<mat.size() && col>=0 && col<mat[0].size()){
                    if(vis[row][col]==0 && mat[row][col]==1){
                        q.push({{row,col},step+1});
                        vis[row][col]=1;
                    }
                }

            }

        }
        return ans;
        
    }
};