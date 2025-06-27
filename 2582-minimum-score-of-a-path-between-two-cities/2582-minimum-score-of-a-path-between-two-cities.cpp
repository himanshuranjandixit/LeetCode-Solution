class Solution {
public:
    vector<int>rank,parent;
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v){
        int ult_u = find(u);
        int ult_v = find(v);
        if(ult_u == ult_v) return ;
        if(rank[ult_u] < rank[ult_v]) parent[ult_u] = ult_v;
        else if(rank[ult_u] > rank[ult_v]) parent[ult_v] = ult_u;
        else{
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        rank.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++) parent[i] = i;
        for(auto it : roads){
            Union(it[0],it[1]);
        }
        int parent_node = find(1);
        int ans=INT_MAX;
        for(auto it:roads){
            if( ( find(it[0]) == find(it[1])) && it[2]<ans ) ans=it[2];
        }
        return ans;
    }
};