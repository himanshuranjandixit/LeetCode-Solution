class Solution {
public:
    vector<int> count;
    int N;
    long result_base_node = 0;

    int dfsBase(unordered_map<int, vector<int>> &adj, int curr, int parent, int depth) {
        int subtree_size = 1;
        result_base_node += depth;
        for(int neighbor : adj[curr]){
            if(neighbor == parent) continue;
            subtree_size += dfsBase(adj, neighbor, curr, depth + 1);
        }
        count[curr] = subtree_size;
        return subtree_size;
    }

    void dfsAdjust(unordered_map<int, vector<int>> &adj, int node, int parent, vector<int> &result) {
        for(int neighbor : adj[node]){
            if(neighbor == parent) continue;
            result[neighbor] = result[node] - count[neighbor] + (N - count[neighbor]);
            dfsAdjust(adj, neighbor, node, result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.resize(n, 0);
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfsBase(adj, 0, -1, 0);
        vector<int>result(n, 0);
        result[0] = result_base_node;
        dfsAdjust(adj, 0, -1, result);
        return result;
    }
};
