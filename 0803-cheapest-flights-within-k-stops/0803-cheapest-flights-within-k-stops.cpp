class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>>price(n,vector<int>(k+2,1e9));
        price[src][0]=0;
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{src,0}});
        int ans=INT_MAX;
        while(!st.empty()){
            int node=st.begin()->second.first;
            int step=st.begin()->second.second;
            int currprice=st.begin()->first;
            st.erase(st.begin());
            if(node==dst){
                return currprice;
            }
            if(step>k) continue;
            for(auto it : adj[node]){
                if(currprice+it.second<price[it.first][step+1]){
                    price[it.first][step+1]=currprice+it.second;
                    st.insert({price[it.first][step+1],{it.first,step+1}});
                }
                
            }

        }
        return -1;
        
    }
};