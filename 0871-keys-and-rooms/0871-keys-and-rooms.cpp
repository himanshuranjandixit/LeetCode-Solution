class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<vector<int>>adj(rooms.size());
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(rooms.size(),0);
        vis[0]=1;
        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(auto it : adj[room]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }

        }
        for(auto it : vis){
            if(it==0) return false;
        }
        return true;
    }
};