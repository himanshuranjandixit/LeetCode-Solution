class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj(n);
        set<pair<int,int>>st;
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            st.insert({it[0],it[1]});
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int val = adj[i].size() + adj[j].size();
                if(st.count({i,j}) || st.count({j,i})) val--;
                ans=max(ans,val);
            }

        }
        return ans;
        
    }
};