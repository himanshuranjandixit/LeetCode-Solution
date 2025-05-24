class Solution {
    set<int>st;
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis,int node,vector<int>& ans){
        // if(vis[node]!=-1) return false;
        vis[node]=1;
        for(auto it :adj[node]){
            if(vis[it]==1) return false;
            if(vis[it]==0 && dfs(adj,vis,it,ans)==false) return false;
        }
        vis[node]=2; 
        if(st.find(node)==st.end()){
            ans.push_back(node);
            st.insert(node);
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int>vis(adj.size(),0);
        vector<int>ans;
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                if(dfs(adj,vis,i,ans)== false) return {};
            }

        }
        return ans;
        
    }
};