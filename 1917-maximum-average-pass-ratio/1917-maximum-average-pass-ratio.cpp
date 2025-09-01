class Solution {
public:
    double gain(int val1, int val2){
        return (double)(val1+1)/(val2+1) - (double)val1/val2;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto it :classes){
            double ratio = gain(it[0],it[1]);
            pq.push({ratio,{it[0],it[1]}});
        }
        while(extraStudents--){
            double ratio = pq.top().first;
            int n = pq.top().second.first;
            int d = pq.top().second.second;
            pq.pop();
            double nratio = gain(n+1,d+1);
            pq.push({nratio,{n+1,d+1}});
        }
        double ans = 0;
        while(!pq.empty()){
            ans += (double)pq.top().second.first / pq.top().second.second;
            pq.pop();
        }
        return ans/classes.size();

    }
};