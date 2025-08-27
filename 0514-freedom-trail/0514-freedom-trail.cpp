class Solution {
public:
vector<vector<int>>dp;
    int dfs(unordered_map<char,vector<int>>& adj, string& ring, string& key, int ringindx, int keyindx){
        if(keyindx==key.size()) return 0;
        if(dp[ringindx][keyindx]!=-1) return dp[ringindx][keyindx];
        int ans = INT_MAX;
        for(auto it : adj[key[keyindx]]){
            int distance = abs(ringindx-it);
            int rotation = min(distance,(int)ring.size()-distance);
            ans=min(ans,rotation+1+dfs(adj,ring,key,it,keyindx+1));
        }
        return dp[ringindx][keyindx] = ans;

    }
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>>adj;
        for(int i=0;i<ring.size();i++){
            adj[ring[i]].push_back(i);
        }
        dp.assign(ring.size()+1,vector<int>(key.size()+1,-1));
        return dfs(adj,ring,key,0,0);
    }
};