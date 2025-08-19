class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>ans;
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,firstPerson});
        pq.push({0,0});
        while(!pq.empty()){
            int person = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            if(!vis[person]) ans.push_back(person);
            vis[person]=1;
            for(auto it:adj[person]){
                if(vis[it.first]==0 && it.second>=time){
                    pq.push({it.second,it.first});
                }
            }
        }
        return ans;
        
    }
};