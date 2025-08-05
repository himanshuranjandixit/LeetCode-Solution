class Solution {
public:
vector<int>vis;
int m =1e9 +7;
    int dfs(unordered_map<int,vector<int>>& adj, int node){
        int maxi=0;
        vis[node]=1;
        for(auto it:adj[node]){
            if(it!=node && !vis[it]){
                maxi = max(maxi,1 + dfs(adj,it));
            }
        }
        return maxi;

    }
    int fastexpo(long long base, long long exp){
        long long ans =1;
        while(exp>0){
            if(exp%2==1){
            ans =(ans*base)%m;
            }
            base =(base*base)%m;
            exp/=2;
        }
        return ans;

    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int n = adj.size();
        vis.resize(n+1,0);
        int edge = dfs(adj,1);
        return fastexpo(2,edge-1);
    }
}; 