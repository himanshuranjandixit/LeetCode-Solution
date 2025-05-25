class Solution {
    set<int>terminal;
public:
    void dfs(vector<vector<int>>& graph, vector<int>vis,set<int>& ans,int node){
        vis[node]=1;
        int check=true;
        for(auto it : graph[node]){
            if(terminal.find(it)==terminal.end()) check=false;
            if(vis[it]==0) dfs(graph,vis,ans,it);
        }
        if(check) ans.insert(node);

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // vector<int>vis(graph.size(),0);
        // set<int>ans;
        // for(int i=0;i<graph.size();i++){
        //     if(graph[i].size()==0) terminal.insert(i);

        // }
        // for(int i=0;i<graph.size();i++){
        //     if(vis[i]==0) dfs(graph,vis,ans,i);
        // }
        // vector<int>safe;
        // for(auto it:ans){
        //     safe.push_back(it);
        // }
        // return safe;
        vector<vector<int>>rev(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                rev[graph[i][j]].push_back(i);
            }
        }
        vector<int>ingoing(graph.size(),0);
        for(int i=0;i<rev.size();i++){
            for(int j=0;j<rev[i].size();j++){
                ingoing[rev[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<ingoing.size();i++){
            if(ingoing[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : rev[node]){
                ingoing[it]--;
                if(ingoing[it]==0) q.push(it);
            }


        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};