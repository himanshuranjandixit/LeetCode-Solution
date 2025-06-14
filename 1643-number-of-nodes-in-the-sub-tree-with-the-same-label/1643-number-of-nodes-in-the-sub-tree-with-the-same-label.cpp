class Solution {
public:
     vector<int>ans;
     vector<int> dfs(vector<vector<int>>& adj, string& labels, int node, int par){
        vector<int>v(26,0);
        v[labels[node]-'a']++;
        for(auto it :adj[node]){
            if(it==par) continue;
            vector<int>childcount = dfs(adj,labels,it,node);
            for(int i=0;i<26;i++){
                v[i]+=childcount[i];
            }
        }
        ans[node] =v[labels[node]-'a'];
        return v;
 
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        ans.resize(n);
        vector<int> v = dfs(adj,labels,0,-1);
        return ans;

        
    }
};