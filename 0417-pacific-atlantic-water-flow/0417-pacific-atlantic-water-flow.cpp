class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            v[0][j]+=1;
        }
        for(int i=1;i<n;i++){
            v[i][0]+=1;
        }
        for(int i=0;i<m;i++){
            v[n-1][i]+=1;
        }
        for(int i=0;i<n-1;i++){
            v[i][m-1]+=1;
        }

        // from ATLANTICS OCEAN


        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq; // {height,{row,col}}
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            pq.push({heights[i][m-1],{i,m-1}});
            vis[i][m-1]=1;
        }
        for(int i=0;i<m-1;i++){
            pq.push({heights[n-1][i],{n-1,i}});
            vis[n-1][i]=1;
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int h = it.first;
            int row = it.second.first;
            int col = it.second.second;
            int drow[4]={0,-1,0,1};
            int dcol[4]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    if(heights[nrow][ncol]>=h){
                        v[nrow][ncol]+=1;
                        pq.push({heights[nrow][ncol],{nrow,ncol}});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }

        // FROM PACIFIC OCEAN 
        
        vis.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            pq.push({heights[i][0],{i,0}});
            vis[i][0]=1;
        } 
        for(int i=1;i<m;i++){
            pq.push({heights[0][i],{0,i}});
            vis[0][i]=1;
        }
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int h = it.first;
            int row = it.second.first;
            int col = it.second.second;
            int drow[4]={0,-1,0,1};
            int dcol[4]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    if(heights[nrow][ncol]>=h){
                        v[nrow][ncol]+=1;
                        pq.push({heights[nrow][ncol],{nrow,ncol}});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }  
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==2) ans.push_back({i,j});
            }
        }  
        return ans;
    }
};