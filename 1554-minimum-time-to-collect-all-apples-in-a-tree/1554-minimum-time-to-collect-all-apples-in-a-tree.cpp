class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int node,int par){
        int time =0;
        for(auto it : adj[node]){
            if(it==par) continue;
            int childtime = dfs(adj,hasApple,it,node);
            if(childtime>0 || hasApple[it]){
                time+=childtime+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(adj,hasApple,0,-1);
      



        
    }
};