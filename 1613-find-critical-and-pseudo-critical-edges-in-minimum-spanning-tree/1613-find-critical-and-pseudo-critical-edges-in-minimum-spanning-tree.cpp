class Solution {
public:
    vector<int> parent, rank;
    void init(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int node){
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v) {
        int ult_u = find(u);
        int ult_v = find(v);
        if (ult_u == ult_v)
            return;
        if (rank[ult_u] > rank[ult_v]) {
            parent[ult_v] = ult_u;
        }
        else if (rank[ult_u] < rank[ult_v]) {
            parent[ult_u] = ult_v;
        } 
        else {
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }

    int spanning(int n, vector<vector<int>>& edges, int skip, int force ) {
        init(n);
        int mst = 0;

        if(force != -1){
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];
            Union(u, v);
            mst += w;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (find(u) != find(v)) {
                Union(u, v);
                mst += w;
            }
        }
        int root = find(0);
        for (int i = 1; i < n; ++i)
            if (find(i) != root)
                return 1e9;  
        return mst;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            edges[i].push_back(i); 
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        int mst = spanning(n, edges,-1,-1);
        vector<int> critical, pseudo_critical;
        for (int i = 0; i < m; ++i) {
            int curr_mst = spanning(n, edges,i,-1);
            if(curr_mst > mst){
                critical.push_back(edges[i][3]);
            }
            else{
                curr_mst = spanning(n, edges,-1,i);
                if(curr_mst == mst) pseudo_critical.push_back(edges[i][3]);
            }
        }
        sort(critical.begin(), critical.end());
        sort(pseudo_critical.begin(), pseudo_critical.end());
        return {critical, pseudo_critical};
    }
};