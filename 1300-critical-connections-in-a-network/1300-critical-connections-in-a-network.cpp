class Solution {
    int timer=1;
private:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node,int par, int low[], int tin[], vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]= timer; 
        low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(it==par) continue;
            if(vis[it]==0){
                dfs(adj,vis,it,node,low,tin,bridges);
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }


    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int low[n];
        int tin[n];
        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        dfs(adj,vis,0,-1,low,tin,bridges);
        return bridges;

        
    }
};