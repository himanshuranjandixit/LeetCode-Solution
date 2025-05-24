class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis,int node){
        // if(vis[node]!=-1) return false;
        vis[node]=1;
        for(auto it :adj[node]){
            if(vis[it]==1) return false;
            if(vis[it]==0 && dfs(adj,vis,it)==false) return false;
        }
        vis[node]=2; 
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>vis(adj.size(),0);
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                if(dfs(adj,vis,i)== false) return false;
            }

        }
        return true;
        
    }
};