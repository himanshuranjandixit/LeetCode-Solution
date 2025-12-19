class Solution {
public:
    vector<int> par;
    int find(int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu != pv){
            par[pu] = pv;
        }
    }
    void reset(int u){
        par[u]=u;
    }
    bool connected(int u, int v){
        return find(u) == find(v);
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        sort(meetings.begin(),meetings.end(),[](vector<int> &a, vector<int> &b){
            return a[2]<b[2];
        });
        map<int,vector<pair<int,int>>> sameMeetings;
        for(auto it:meetings){
            sameMeetings[it[2]].push_back({it[0],it[1]});
        }
        unite(0,firstPerson);
        for(auto [t,meetings] : sameMeetings){
            for(auto [u,v]:meetings){
                unite(u,v);
            }
            for(auto [u,v]:meetings){
                if(!connected(u,0)){
                    reset(u);
                    reset(v);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(connected(i,0)){
                ans.push_back(i);
            }
        }
        return ans;


        
    }
};