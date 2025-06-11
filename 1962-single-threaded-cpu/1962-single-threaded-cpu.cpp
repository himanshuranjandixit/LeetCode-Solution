class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>>v;
        for(int i=0;i<tasks.size();i++){
            v.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(begin(v),end(v));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        long long time=0;
        int indx=0;
        vector<int>ans;
        while(indx < n || !pq.empty()){
            if(pq.empty() && time<v[indx][0]){
                time=v[indx][0];
            }
            while(indx<n && v[indx][0]<=time){
                pq.push({v[indx][1],v[indx][2]});
                indx++;
            } 
            auto it =pq.top();
            pq.pop();
            time+=it.first;
            ans.push_back(it.second);


        }
        return ans;

        
    }
};