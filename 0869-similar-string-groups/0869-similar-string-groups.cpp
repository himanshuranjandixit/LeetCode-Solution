class Solution {
public:
    vector<int> parent;int count;
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ult_u =findUpar(u);
        int ult_v = findUpar(v);
        if(ult_u != ult_v){
            count--;
            parent[ult_u]=ult_v;
        }
    }
    bool Similar(string &s1, string &s2){
        int diff=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) diff++;
        }
        return diff==2 || diff==0;

    }

    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(adj,vis,it);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        // int n = strs.size();
        // parent.resize(n);
        // for(auto i=0;i<n;i++){
        //     parent[i]=i;
        // }
        // count=n;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(Similar(strs[i],strs[j])) {
        //             unionByRank(i,j);

        //         }
        //     }

        // }
        // return count;
        int n = strs.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(Similar(strs[i],strs[j])){
                    v.push_back({i,j});
                }
            }
        }
        vector<vector<int>>adj(n);
        for(auto it :v){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<int>vis(n,0);
        count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                count++;
            }
        }
        return count;


        
    }
};