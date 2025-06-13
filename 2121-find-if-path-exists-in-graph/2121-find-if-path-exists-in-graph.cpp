class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>v(n);
        for(auto it :edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(source);
        vis[source]=1;
        while(!q.empty()){
            int node = q.front();q.pop();
            if(node==destination) return true;
            for(auto it : v[node]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
        
    }
};