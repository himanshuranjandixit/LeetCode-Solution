class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>time(n+1,1e9);
        time[k]=0;
        time[0]=0;
        set<pair<int,int>>st;
        st.insert({0,k});
        while(!st.empty()){
            int t = st.begin()->first;
            int node=st.begin()->second;
            st.erase(st.begin());
            for(auto it: adj[node]){
                if(t+it.second<time[it.first]){
                    time[it.first]=t+it.second;
                    st.insert({time[it.first],it.first});
                }
            }
        }
        int ans=0;
        for(auto it:time){
            if(it==1e9) return -1;
            ans=max(ans,it);
        }
        return ans;

        
    }
};