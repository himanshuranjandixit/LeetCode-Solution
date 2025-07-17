class Solution {
public:
    vector<int>parent,bit;
    int find(int node){
        if(parent[node]==node) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u , int v){
        parent[v]=u;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        bit.resize(n,-1);
        for(int i=0;i<n;i++){
            parent[i]=i;
            bit[i]=-1;
        }
        for(auto it :edges){
            int par_u = find(it[0]);
            int par_v = find(it[1]);
            if(par_u != par_v ){
                bit[par_u] &= bit[par_v];
                Union(par_u,par_v);
            }
            bit[par_u]&=it[2];

        }

        vector<int>ans;
        for(auto it:query){
            int par1 = find(it[0]);
            int par2 = find(it[1]);
            if(par1!=par2) ans.push_back(-1);
            else ans.push_back(bit[par1]);
        }
        return ans;
        
    }
};