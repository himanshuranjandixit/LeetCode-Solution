class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : meetings){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>ans(n,0);
        ans[0]=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,firstPerson});
        pq.push({0,0});
        while(!pq.empty()){
            int person = pq.top().second;
            int time = pq.top().first;
            pq.pop();
            ans[person]=1;
            for(auto it:adj[person]){
                if(ans[it.first]==0 && it.second>=time){
                    pq.push({it.second,it.first});
                }
            }
        }
        vector<int>res;
        for(int i=0;i<n;i++){
            if(ans[i]) res.push_back(i);
        }
        return res;
        
    }
};