class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<vector<string>>& accounts, vector<int>& vis, set<string>& st, int node){
        vis[node]=1;
        for(int i=1;i<accounts[node].size();i++){
            st.insert(accounts[node][i]);
        }
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(adj,accounts,vis,st,it);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<int>>adj(accounts.size());
        unordered_map<string, vector<int>>mpp;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                mpp[accounts[i][j]].push_back(i);
            }
        }
        for(auto it:mpp){
            for(int i=1;i<it.second.size();i++){
                int u =it.second[0];
                int v= it.second[i];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        // for(int i=0;i<accounts.size()-1;i++){
        //     for(int k=1;k<accounts[i].size();k++){
        //         string s=accounts[i][k];
        //         for(int j=i+1;j<accounts.size();j++){
        //             if(accounts[i][0]!=accounts[j][0]) continue;
        //             for(int l=1;l<accounts[j].size();l++){
        //                 string ss = accounts[j][l];
        //                 if(s==ss){
        //                     adj[i].push_back(j);
        //                     adj[j].push_back(i);
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        vector<vector<string>> ans;
        set<string>st;
        vector<int>vis(accounts.size(),0);
        for(int i=0;i<accounts.size();i++){
            if(vis[i]==0){
                vector<string>v;
                v.push_back(accounts[i][0]);
                dfs(adj,accounts,vis,st,i);
                while(!st.empty()){
                    v.push_back(*(st.begin()));
                    st.erase(st.begin());
                }
                sort(v.begin()+1,v.end());
                ans.push_back(v);
                st.clear();
            }

        }
        return ans;
        
    }
};