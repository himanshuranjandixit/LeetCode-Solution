class Solution {
public:
    void dfs(vector<vector<int>>& stones, int indx, vector<int>& vis){
        vis[indx]=1;
        int row = stones[indx][0];
        int col = stones[indx][1];
        for(int i=0;i<stones.size();i++){
            if((!vis[i]) && (stones[i][0]==row || stones[i][1]==col)){
                dfs(stones,i,vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n,0);
        int group=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(stones,i,vis);
                group++;
            }

        }
        return n-group;
        
    }
};