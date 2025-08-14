class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            pq.push({height[i][0],{i,0}});
            pq.push({height[i][m-1],{i,m-1}});
            vis[i][0]=1;
            vis[i][m-1]=1;
        }
        for(int i=0;i<m;i++){
            pq.push({height[0][i],{0,i}});
            pq.push({height[n-1][i],{n-1,i}});
            vis[0][i]=1;
            vis[n-1][i]=1;
        }
        int ans = 0;
        while(!pq.empty()){
            int h = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            int drow[4] = {0,-1,0,1};
            int dcol[4] = {1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow <n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                    ans += max(h - height[nrow][ncol],0);
                    pq.push({max(h,height[nrow][ncol]),{nrow,ncol}});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return ans;
        
    }
};