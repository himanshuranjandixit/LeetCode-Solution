class Solution {
public:
    unordered_map<int, deque<int>> adj; 
    vector<vector<int>> ans;
    void dfs(int node, vector<int>& path) {
        auto& neighbors = adj[node];
        while(!neighbors.empty()){
            int next = neighbors.front();
            neighbors.pop_front();
            dfs(next, path);
        }
        path.push_back(node);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, int> indegree, outdegree;
        for(auto& it : pairs){
            adj[it[0]].push_back(it[1]);
            outdegree[it[0]]++;
            indegree[it[1]]++;
        }

        int start = pairs[0][0];
        for(auto it: adj) {
            if(outdegree[it.first] - indegree[it.first] == 1) {
                start = it.first;
                break;
            }
        }
        vector<int> path;
        dfs(start,path);
        reverse(path.begin(),path.end());
        for(int i = 0; i < path.size() - 1; ++i){
            ans.push_back({path[i], path[i + 1]});
        }

        return ans;
    }
};
