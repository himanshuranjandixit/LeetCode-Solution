class Graph {
public:
vector<vector<pair<int,int>>>adj;
int n;
    Graph(int _n, vector<vector<int>>& edges) {
        n=_n;
        adj.resize(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
        
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        pq.push({0,node1});
        vector<long long>vis(n,LLONG_MAX);
        while(!pq.empty()){
            int node = pq.top().second;
            long long cost = pq.top().first;pq.pop();
            if(node==node2) return (int)cost;
            if(cost>vis[node]) continue;
            for(auto it:adj[node]){
                if(vis[it.first] > cost + it.second){
                    vis[it.first] = cost + it.second;
                    pq.push({cost+it.second,it.first});
                }
            }
        }
        return -1;
        
    }

};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */