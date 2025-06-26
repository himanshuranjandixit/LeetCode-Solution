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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        for(auto i=0;i<n;i++){
            parent[i]=i;
        }
        count=n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(Similar(strs[i],strs[j])) {
                    unionByRank(i,j);

                }
            }

        }
        return count;

        
    }
};