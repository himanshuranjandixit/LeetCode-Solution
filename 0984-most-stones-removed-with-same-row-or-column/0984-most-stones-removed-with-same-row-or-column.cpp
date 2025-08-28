class Solution {
public:
    vector<int>parent,rank;
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void Union(int u, int v){
        int ult_u = find(u);
        int ult_v = find(v);
        if(ult_u == ult_v) return ;
        if(rank[ult_u]>rank[ult_v]){
            parent[ult_v] = ult_u;
        }
        else if (rank[ult_u]<rank[ult_v]){
            parent[ult_u]=parent[ult_v];
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((stones[i][0] == stones[j][0]) || (stones[i][1] == stones[j][1])){
                    Union(i,j);
                }
            }
        }
        int groups = 0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) groups++;
        }
        return n- groups;

        
    }
};