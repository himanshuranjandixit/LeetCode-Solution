class Solution {
public:
    vector<int>rank,par;
    int find(int u){
        if(u==par[u]) return u;
        return par[u]=find(par[u]);
    }
    void Union(int u, int v){
        int ult_u=find(u);
        int ult_v=find(v);
        if(ult_u ==ult_v) return;
        if(rank[ult_u]< rank[ult_v]) par[ult_u] =ult_v;
        else if(rank[ult_u]>rank[ult_v]) par[ult_v] = ult_u;
        else{
            par[ult_u] =ult_v;
            rank[ult_v] ++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        rank.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        sort(edgeList.begin(),edgeList.end(),[](const vector<int> &a, const vector<int> &b){
            return a[2]<b[2];
        });
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),[](const vector<int> &a, const vector<int> &b){
            return a[2]<b[2];
        });
        vector<bool>ans(queries.size(),false);
        int j=0;
        for(auto it :queries){
            int start =it[0];
            int end= it[1];
            int maxval =it[2];
            int idx =it[3];
            while(j<edgeList.size() && edgeList[j][2]<maxval){
                Union(edgeList[j][0],edgeList[j][1]);
                j++;
            }
            if(find(start)==find(end)) ans[idx]=true;
        }
        return ans;
    }
};