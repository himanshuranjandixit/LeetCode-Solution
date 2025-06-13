class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto it : dislikes){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n+1,-1);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int person = q.front();q.pop();
                    int grp = vis[person];
                    for(auto it :adj[person]){
                        if(vis[it]==-1){
                            vis[it]=grp^1;
                            q.push(it);
                        }
                        else if(vis[it]==grp) return false;
                    }
                }
            }
        }
        return true;
    }
};