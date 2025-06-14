class Solution {
public:
    int ans=1;
    int dfs(vector<vector<int>>& adj, int node, int par, string& s ){
        int max1=0;
        int max2=0;
        for(auto &it: adj[node]){
            if(it==par) continue;
            int childlen = dfs(adj,it,node,s);
            if(s[it]!=s[node]){
                if(childlen>max1){
                    max2=max1;
                    max1=childlen;
                }
                else if(childlen>max2){
                    max2=childlen;
                }
            }
        }
        ans=max(ans,1+max1+max2);
        return 1+max1;

    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>v(parent.size());
        for(int i=0;i<parent.size();i++){
            if(parent[i]==-1) continue;
            v[i].push_back(parent[i]);
            v[parent[i]].push_back(i);
        }
        dfs(v,0,-1,s);
        return ans;


        
    }
};                            