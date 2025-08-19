class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n-1;i++){
            adj[i][i+1]=1;
            adj[i+1][i]=1;
        }
        adj[x-1][y-1] =1;
        adj[y-1][x-1] =1;
        // cout<<adj[x-1][y-1]<<endl;
        // cout<<adj[y-1][x-1]<<endl;
        // if(abs(x-y)!=1){
        //     adj[x-1][y-1]=1;
        //     adj[y-1][x-1]=1;
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(adj[j][i]== INT_MAX || adj[i][k]==INT_MAX) continue;
                    adj[j][k] = min(adj[j][k],adj[j][i] + adj[i][k]);
                }
            }
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int step = adj[i][j];
                if(step-1<n) ans[step-1]++;

            }
        }
        return ans;


        
    }
};