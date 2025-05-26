class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n =heights.size();int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        set<pair<int,pair<int,int>>>st;
        st.insert(make_pair(dist[0][0],make_pair(0,0)));
        while(!st.empty()){
            int row=st.begin()->second.first;
            int col=st.begin()->second.second;
            int val =st.begin()->first;
            st.erase(st.begin());
            int drow[]={0,-1,0,1};
            int dcol[]={1,0,-1,0};
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int currval=max(val,abs(heights[nrow][ncol]-heights[row][col]));
                    if(currval<dist[nrow][ncol]){
                        // cout<<nrow<<" "<<ncol<<endl;
                        st.erase(make_pair(dist[nrow][ncol],make_pair(nrow,ncol)));
                        dist[nrow][ncol]=currval;
                        st.insert(make_pair(dist[nrow][ncol],make_pair(nrow,ncol)));
                    }
                }
            }
        }
        return dist[n-1][m-1];
        
    }
};