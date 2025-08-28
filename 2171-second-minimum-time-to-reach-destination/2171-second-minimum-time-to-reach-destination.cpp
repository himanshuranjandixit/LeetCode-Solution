class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,1});
        int shortestime = -1;
        bool hassecondsmallest = false;
        vector<vector<int>>dist(n+1);
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            // cout<<node<<" "<<t<<endl;
            pq.pop();
            if(node==n){
                if(hassecondsmallest && shortestime!=t) return t;
                hassecondsmallest = true;
                shortestime = t;
            }
            if(dist[node].size()>0 && dist[node].back()==t) continue;
            if(dist[node].size()==2) continue;
            dist[node].push_back(t);
            if((t/change)%2!=0) t =(t/change+1)*change;
            for(auto it :adj[node]){
                pq.push({t+time,it});
            }
        }
        return -1;
        
        
    }
};