class Solution {
public:
    int dp[50001];
    int dfs(vector<vector<pair<int,int>>>& adj, int node,vector<int>& time){
        int totaltime =0;
        if(dp[node]!=-1) return dp[node];
        for(auto it: adj[node]){
            totaltime = max(totaltime,dfs(adj,it.first,time));
        } 
        // cout<<node<<endl;
        return dp[node] =  time[node-1]  + totaltime;
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>indegree(n+1);
        for(auto it : relations){
            adj[it[1]].push_back({it[0],time[it[0]-1]});
            indegree[it[0]]++;
        }
        vector<int>final;
        for(int i=0;i<n+1;i++) if(indegree[i]==0 && i!=0) final.push_back(i);
        // cout<<final[0]<<endl;
        memset(dp,-1,sizeof(dp));
        int ans = dfs(adj,final[0],time);
        for(int i=1;i<final.size();i++){
            ans = max(ans,dfs(adj,final[i],time));
        }
        return ans;


        
    }
};