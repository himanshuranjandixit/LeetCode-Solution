class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if(ulp_u<ulp_v) parent[ulp_v]=ulp_u;
        else  parent[ulp_u]=ulp_v;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        for(int i =0; i<s1.size();i++){
            ds.unionByRank(s1[i]-'a',s2[i]-'a');
        }
        string ans="";
        for(auto it:baseStr){
            char ch = ds.findUPar(it-'a');
            ans+=(ch+'a');

        }
        return ans;
        
    }
};