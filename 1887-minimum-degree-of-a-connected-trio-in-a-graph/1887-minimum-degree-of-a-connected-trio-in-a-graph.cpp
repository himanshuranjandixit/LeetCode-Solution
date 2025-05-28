class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        vector<int>degree(n+1,0);
        for(auto it :edges){
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
            degree[it[0]]++;
            degree[it[1]]++;
        }
        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=n;k++){
                    if(adj[i][j]==1 && adj[j][k]==1 && adj[i][k]==1){
                        ans=min(ans,degree[i]+degree[j]+degree[k]-6);
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};