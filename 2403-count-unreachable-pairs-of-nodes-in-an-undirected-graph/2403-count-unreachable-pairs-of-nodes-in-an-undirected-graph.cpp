class Solution {
public:
    void dfs(vector<vector<int>>&adj, vector<int>& vis, int node, int& count){
        vis[node]=1;
        for(auto it :adj[node]){
            if(!vis[it]){
                count++;
                dfs(adj,vis,it,count);
            }
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>groups;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            int count=1;
            if(!vis[i]){
                dfs(adj,vis,i,count);
                groups.push_back(count);
            }
        }
        long long ans=0,sum=0;
        for(int i=0;i<groups.size();i++){
            ans += 1LL* groups[i]*(n-groups[i]-sum);
            sum+=groups[i];
        }
        return ans;
        
    }
};