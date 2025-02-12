class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans(image);
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.emplace(sr,sc);
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int drow[4]={-1,0,1,0};
            int dcol[4]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int row=i+drow[k];
                int col=j+dcol[k];
                if(row>=0 && row<n && col>=0 && col<m){
                    if(vis[row][col]==0 && image[row][col]==image[i][j]){
                        ans[row][col]= color;
                        ans[i][j]=color;
                        q.emplace(row,col);
                        vis[i][j]=1;
                    }
                }
            }

        }
        ans[sr][sc]=color;
        return ans;

        
    }
};