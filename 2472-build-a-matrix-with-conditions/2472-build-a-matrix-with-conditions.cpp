class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, bool &hasCycle, stack<int>& st){
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it]==0){
                dfs(adj,vis,it,hasCycle,st);
            }
            else if(vis[it]==1){
                hasCycle = true;
                return ;
            }
        }
        st.push(node);
        vis[node]=2;
    }
    vector<int> toposort(vector<vector<int>>& edges, int n){
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>topoOrder;
        stack<int>st;
        bool hasCycle = false;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i,hasCycle,st);
                if(hasCycle) return {};
            }
        }
        while(!st.empty()){
            topoOrder.push_back(st.top());
            st.pop();
        }
        return topoOrder;

    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowtop = toposort(rowConditions,k+1);
        vector<int>coltop = toposort(colConditions,k+1);
        vector<vector<int>>ans(k,vector<int>(k,0));
        if(rowtop.empty() || coltop.empty()) return {};
        for(int i =0 ;i<k;i++){
            for(int j =0;j<k;j++){
                if(rowtop[i]==coltop[j]) ans[i][j] = rowtop[i];
            }
        }
        return ans;
    }
};