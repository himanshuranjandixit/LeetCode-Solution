class Solution {
public:
    vector<int>rank,parent;
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v){
        int ult_u =find(u);
        int ult_v = find(v);
        if(ult_u == ult_v) return ;
        if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_u] > rank[ult_v]) parent [ult_v] = ult_u;
        else{
            parent[ult_u] =ult_v;
            rank[ult_v]++;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[vals[i]].push_back(i);
        }
        int ans=n;
        vector<bool>active(n,false);
        for(auto it:mpp){
            for(auto node : it.second){
                active[node]=true;
                for(auto child : adj[node]){
                    if(active[child]) Union(child,node);
                }
            }
            unordered_map<int,int>par;
            for(auto node :it.second){
                par[find(node)]++;
            }
            int count=0;
            for(auto it :par){
                count += it.second*(it.second-1)/2;
            }
            ans+=count;
        }
        return ans;

        
    }
};