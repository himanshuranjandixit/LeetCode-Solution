class Solution {
public:
    int dfs(vector<vector<int>>& adj,int node, int parent, int k){
        if(k<0) return 0;
        int res =1;
        for(int it:adj[node]){
            if(it==parent) continue;
            res+=dfs(adj,it,node,k-1);
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>>adj1(edges1.size()+1);
        for(int i=0;i<edges1.size();i++){
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        }
        vector<vector<int>>adj2(edges2.size()+1);
        for(int i=0;i<edges2.size();i++){
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int maxi=0;
        for(int i=0;i<edges2.size()+1;i++){
            maxi=max(maxi,dfs(adj2,i,-1,k-1));
        }
        vector<int>count(edges1.size()+1);
        for(int i=0;i<edges1.size()+1;i++){
            count[i]=dfs(adj1,i,-1,k);
        }
        for(int i=0;i<edges1.size()+1;i++){
            count[i]+=maxi;
        }
        return count;


        

        
    }
};