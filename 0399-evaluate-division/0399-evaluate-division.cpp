class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> &adj, unordered_set<string> &vis, string src, string dst, double product, double& ans ){
        if(src == dst){
            ans = product;
            return ;
        }
        vis.insert(src);
        for(auto it : adj[src]){
            if(vis.find(it.first) == vis.end()){
                dfs(adj,vis,it.first,dst,product*it.second,ans);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double>result;
        for(auto &it : queries){
            string src = it[0];
            string dst = it[1];
            double ans = -1.0;
            double product = 1.0;
            if(adj.find(src) != adj.end() && adj.find(dst) != adj.end()){
                unordered_set<string>vis;
                dfs(adj, vis, src, dst, product, ans);
            }
            result.push_back(ans);
        }
        return result;
        
    }
};