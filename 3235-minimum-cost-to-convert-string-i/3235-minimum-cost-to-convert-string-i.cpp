class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,long long>>>adj(26);
        for(int i=0;i<original.size();i++){
            adj[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<long long>>dist(26,vector<long long>(26,INT_MAX));
        for(int i=0;i<26;i++){
            for(auto it:adj[i]){
                dist[i][it.first] = min(dist[i][it.first],it.second);
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(dist[j][i] == INT_MAX || dist[i][k] == INT_MAX) continue;
                    dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
                }
            }
        }
        long long res=0;
        for(int i=0;i<source.size();i++){
            int src = source[i]-'a';
            int end = target[i]-'a';
            if(src == end) continue;
            if(dist[src][end]==INT_MAX) return -1;
            res+=dist[src][end];
        }
        return res;
        long long ans=0;
        for(int i=0;i<source.size();i++){
            int src = source[i]-'a';
            int end = target[i]-'a';
            if(src == end) continue;
            priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<>>pq;
            pq.push({0,src});
            bool ispossible = true;
            vector<long long>dist(26,INT_MAX);
            while(!pq.empty()){
                int node = pq.top().second;
                long long cost=pq.top().first;
                pq.pop();
                if(node==end){
                    ans+=cost;
                    ispossible = false;
                    break;
                }
                for(auto it :adj[node]){
                    if(cost + it.second<dist[it.first]){
                        dist[it.first]=cost + it.second;
                        pq.push({cost+it.second,it.first});
                    }
                }
            }
            if(ispossible) return -1;
        }
        return ans;  
    }
};