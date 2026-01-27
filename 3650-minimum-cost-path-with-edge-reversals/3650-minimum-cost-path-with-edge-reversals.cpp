class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,0});
        vector<int> dist(n, 1e9);
        dist[0]=0;
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(weight>dist[node]) continue;
            if(node==n-1) return weight;
            for(auto it:adj[node]){
                if(weight+it.second<dist[it.first]){
                    pq.push({weight+it.second,it.first});
                    dist[it.first] = weight+it.second;
                }
            }
        }
        return -1;
        
    }
};