class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>v(n,1);
        for(auto it :edges){
            v[it[1]]=0;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(v[i]) ans.push_back(i);
        }
        return ans;
        
    }
};