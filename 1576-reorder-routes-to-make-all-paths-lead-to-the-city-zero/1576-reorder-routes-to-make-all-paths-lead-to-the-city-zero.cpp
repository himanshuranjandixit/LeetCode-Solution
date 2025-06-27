class Solution {
public:
    void dfs(vector<vector<int>>& adj, map<pair<int,int>,int>& mpp, vector<int>& vis, int node, int &count){
        vis[node]=1;
        for(auto it :adj[node]){
            if(!vis[it]){
                if(mpp.count({node,it})) count++;
                dfs(adj,mpp,vis,it,count);
            }

        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        map<pair<int,int>,int>mpp;
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mpp[{it[0],it[1]}]=1;
        }
        int count=0;
        vector<int>vis(n,0);
        dfs(adj,mpp,vis,0,count);
        return  count;
        
    }
};