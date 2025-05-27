class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0) dfs(adj,vis,it);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(adj,vis,i);
            }
        }
        return count-1;
    }
};