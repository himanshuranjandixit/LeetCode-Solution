class disjointset{
    vector<int>rank,parent,size;
public:
    disjointset(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            rank[i]=0;
            size[i]=1;
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionbyrank(int u, int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=parent[pv];
        else if(rank[pv]<rank[pu]) parent[pv]=parent[pu];
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return ;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
        

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones){
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        disjointset ds(maxrow+maxcol+1);
        unordered_map<int,int>mpp;
        for(auto it :stones){
            ds.unionbysize(it[0],it[1]+maxrow+1);
            mpp[it[0]]=1;
            mpp[it[1]+maxrow+1]=1;
        }
        int count=0;
        for(auto it:mpp){
            if(it.first==ds.findUpar(it.first)) count++;

        }
        return stones.size()-count;
        
        
        
    }
};