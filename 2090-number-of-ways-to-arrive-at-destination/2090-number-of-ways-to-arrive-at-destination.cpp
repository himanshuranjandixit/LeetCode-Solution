class Solution {
public:
   int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,long long>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>time(n,INT_MAX);
        set<pair<long long,int>>st;
        time[0]=0;
        st.insert({0,0});
        while(!st.empty()){
            long long t=st.begin()->first;
            int node=st.begin()->second;
            st.erase(st.begin());
            for(auto it:adj[node]){
                if(time[it.first]==INT_MAX || it.second+t<time[it.first]){
                    time[it.first]=it.second+t;
                    st.insert({time[it.first],it.first});
                }
            }
        }
        long long mini=time[n-1];
        st.clear();
        st.insert({0,0});
        vector<long long>count(n,0);
        count[0]=1;
        while(!st.empty()){
            long long t=st.begin()->first;
            int node=st.begin()->second;
            st.erase(st.begin());
            for(auto it:adj[node]){
                if(t+it.second==time[it.first]){
                    count[it.first]=(count[it.first]+count[node])%M;
                    
                }
                if(t+it.second>time[it.first]) continue;
                st.insert({t+it.second,it.first});
            }
        }
        return (int)count[n-1];

        
    }
};