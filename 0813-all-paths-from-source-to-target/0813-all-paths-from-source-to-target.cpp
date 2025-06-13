class Solution {
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& adj, int node,vector<int>& v){
        v.push_back(node);
        if(node==adj.size()-1){
            ans.push_back(v);
            return;
        }
        for(auto it: adj[node]){
            dfs(adj,it,v);
            v.pop_back();
        }


    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>adj;
        for(auto it :graph){
            vector<int>v;
            for(auto itt:it){
                v.push_back(itt);
                
            }
            adj.push_back(v);
        }
        vector<int>v;
        dfs(adj,0,v);
        return ans;
        
    }
};