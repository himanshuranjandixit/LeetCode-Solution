class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            vector<vector<int>>adj(n,vector<int>(n,1e9));
            for(auto it : roads){
                if(((1<<it[0])&i) && ((1<<it[1]) & i)){
                    adj[it[0]][it[1]] = min(adj[it[0]][it[1]],it[2]);
                    adj[it[1]][it[0]] = min(adj[it[1]][it[0]],it[2]);
                }
            }
            for(int j=0;j<n;j++){
                adj[j][j]=0;
            }
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        adj[k][l] = min(adj[k][l],adj[k][j] + adj[j][l]);
                    }
                }
            }
            bool check = true;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(k==j) continue;
                    if(((1<<j) & i) && ((1<<k) & i)){
                        if(adj[j][k] > maxDistance){
                            check = false;
                            break;
                        }
                    }
                }
            }
            if(check) ans++;

        }
        return ans;
        
    }
};