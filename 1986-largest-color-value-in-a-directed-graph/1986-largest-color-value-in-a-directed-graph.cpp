class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        vector<vector<int>>v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                v[i][colors[i]-'a']++;
            }
        }
        int count=0;
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            int col=colors[node];
            q.pop();
            ans=max(ans,v[node][col-'a']);
            count++;
            for(auto it :adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
                for(int i=0;i<26;i++){
                    if(colors[it]-'a'==i) v[it][i]=max(v[it][i],v[node][i]+1);
                    else v[it][i]=max(v[it][i],v[node][i]);
                }
            }
            
        }
        if(count!=n) return -1;
        return ans;
        
    }
};