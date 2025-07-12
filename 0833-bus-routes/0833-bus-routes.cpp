class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<routes.size();i++){
            for(auto it :routes[i]){
                mpp[it].push_back(i);
            }
        }
        queue<int>q;
        unordered_set<int>st;
        for(auto it:mpp[source]){
            q.push(it);
            st.insert(it);
        }
        int ans=1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int route = q.front();
                q.pop();
                for(auto it : routes[route]){
                    if(it == target) return ans;
                    for(auto nextroute : mpp[it]){
                        if(st.count(nextroute)) continue;
                        st.insert(nextroute);
                        q.push(nextroute);
                    }
                }
            }
            ans++;
        }
        return -1;

        
    }
};