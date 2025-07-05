class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq; //{probability,curr_node}
        pq.push({1.0,start_node});
        vector<double>max_prob(n,0.0);
        max_prob[start_node]=1.0;
        double ans=0;
        while(!pq.empty()){
            int curr_node = pq.top().second;
            double curr_prob = pq.top().first;
            pq.pop();
            if(curr_node == end_node) ans=max(ans,curr_prob);
            for(auto it:adj[curr_node]){
                double updated_prob = curr_prob * it.second;
                if(max_prob[it.first] < updated_prob){
                    max_prob[it.first] = updated_prob;
                    pq.push({updated_prob,it.first});
                }
            }
        }
        return ans;
        
    }
};