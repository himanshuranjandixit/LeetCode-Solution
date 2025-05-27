class disjointset{
public:
    vector<int>rank,parent,size;
    disjointset(int n){
        rank.resize(n+1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
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
        if(pu==pv) return ;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else {
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u, int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointset ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        int node1=row*n+col;
                        int node2=nrow*n+ncol;
                        ds.unionbysize(node1,node2);
                    }
                }
            }
        }
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                set<int>st;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                        st.insert(ds.findUpar(nrow*n+ncol));
                        
                    }
                }
                int val=0;
                for(auto it:st){
                    val+=ds.size[it];
                }
                ans=max(ans,val+1);
            }
        }
        for(int node=0;node<n*n;node++){
            ans=max(ans,ds.size[ds.findUpar(node)]);
        }
        return ans;
        
    }
};