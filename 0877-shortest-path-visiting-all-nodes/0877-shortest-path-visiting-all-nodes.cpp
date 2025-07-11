class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n==1) return 0;
        queue<pair<int,int>>q;
        set<pair<int,int>>vis;
        for(int i=0;i<n;i++){
            q.push({i,(1<<i)});
            vis.insert({i,(1<<i)});
        }
        int allvis = (1<<n)-1;
        int ans=0;
        while(!q.empty()){
            ans++;
            int N =q.size();
            while(N--){
                int node = q.front().first;
                int mask = q.front().second;
                q.pop();
                for(auto &it :graph[node]){
                    int nextmask = mask | (1<<it);
                    if(nextmask==allvis) return ans;
                    if(vis.find({it,nextmask})==vis.end()){
                        q.push({it,nextmask});
                        vis.insert({it,nextmask});
                    }
                }
            }
        }
        return -1;
        
        
    }
};