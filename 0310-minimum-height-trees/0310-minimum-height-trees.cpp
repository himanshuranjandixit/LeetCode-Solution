class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        int totalNodes = n;
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }
        queue<int>q;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
                vis[i]=true;
            }
        }
        while(totalNodes>2){
            int size = q.size();
            while(size--){
                int node =q.front();
                q.pop();
                totalNodes--;
                for(auto it:adj[node]){
                    degree[it]--;
                    if(degree[it]==1) q.push(it);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;

        
    }
};