class Solution {
public:
    vector<int> bfs(vector<vector<pair<int,int>>>&adj,int node, int n ){
        vector<int>dist(n,INT_MAX);
        dist[node]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq; //{distance,node}
        pq.push({0,node});
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distance>dist[node]) continue;
            for(auto it :adj[node]){
                if(distance + it.second<dist[it.first]){
                    dist[it.first] = distance + it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist;

    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dist1 = bfs(adj,0,n);
        vector<int>dist2 = bfs(adj,n-1,n);
        vector<bool>ans(edges.size(),false);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if((dist1[u] != INT_MAX) && (dist2[v]!=INT_MAX) && (dist1[u] + w + dist2[v] == dist1[n-1] )) ans[i] =true;
            if( (dist1[v] != INT_MAX) && (dist2[u]!=INT_MAX ) && (dist1[v] + w + dist2[u] == dist1[n-1]) ) ans[i] = true;
        }
        return ans;
        
    }
};