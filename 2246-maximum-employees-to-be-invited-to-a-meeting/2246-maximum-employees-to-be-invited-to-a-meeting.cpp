class Solution {
public:
    int bfs(unordered_map<int,vector<int>>&adj,int node,vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push({node,0});
        int maxDist = 0;
        while(!q.empty()){
            int currNode = q.front().first;
            int dist = q.front().second;
            q.pop();
            for(auto it : adj[currNode]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,dist+1});
                    maxDist=max(maxDist,dist+1);
                }
            }

        }
        return maxDist;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int,vector<int>>adj;
        for(int i = 0 ; i<n;i++){
            int u = i;
            int v = favorite[i]; // u->v
            adj[v].push_back(u);
        }
        int cycle =0;
        int coupleCycle =0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_map<int,int>mpp; //{node,node visted}
                int currNode = i;
                int nodeCount = 0;
                while(!vis[currNode]){
                    vis[currNode]=true;
                    mpp[currNode]=nodeCount;
                    int nextNode = favorite[currNode];
                    nodeCount++;
                    if(mpp.count(nextNode)){
                        int cyclelength = nodeCount  - mpp[nextNode];
                        cycle = max(cycle,cyclelength);
                        if(cyclelength==2){
                            vector<bool>visited(n,false);
                            visited[currNode]=true;
                            visited[nextNode] =true;
                            coupleCycle += 2 + bfs(adj,currNode,visited) + bfs(adj,nextNode,visited);
                        }
                        break;
                    }
                    currNode =nextNode;
                }
            }
        }
        return max(coupleCycle,cycle);

        
    }
};