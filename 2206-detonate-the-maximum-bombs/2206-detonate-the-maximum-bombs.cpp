typedef long long ll;
class Solution {
public:
   
    bool isPossible(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2){
        return (( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) <= r1*r1);
    }
    void dfs(vector<vector<int>>& adj, int node, vector<int>& vis, int &count){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                count++;
                dfs(adj,it,vis,count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>>adj(bombs.size());
        for(int i=0;i<bombs.size();i++){
            for(int j=0;j<bombs.size();j++){
                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];
                if(i != j && isPossible(x1,y1,r1,x2,y2,r2)){
                    adj[i].push_back(j);
                }
            }

        }
        int ans=1;
        // int i=0;
        // for(auto it :adj){
        //     cout<<i<<"  ";
        //     for(auto itt:it){
        //         cout<<itt<<" ";
        //     }
        //     i++;
        //     cout<<endl;
        // }


        vector<int>vis(bombs.size(),0);
        for(int i=0;i<bombs.size();i++){
            if(!vis[i]){
                vector<int>vis(bombs.size(),0);
                int count=1;
                dfs(adj,i,vis,count);
                ans=max(ans,count);
            }
        }
        return ans;

        
    }
};