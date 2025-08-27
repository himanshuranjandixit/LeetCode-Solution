class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& adj, vector<int>& vis,vector<int>& ancestor, int node){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                ancestor.push_back(it);
                dfs(adj,vis,ancestor,it);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            vector<int>ancestor;
            dfs(adj,vis,ancestor,i);
            sort(ancestor.begin(),ancestor.end());
            ans.push_back(ancestor);
        }
        return ans;

        
    }
};