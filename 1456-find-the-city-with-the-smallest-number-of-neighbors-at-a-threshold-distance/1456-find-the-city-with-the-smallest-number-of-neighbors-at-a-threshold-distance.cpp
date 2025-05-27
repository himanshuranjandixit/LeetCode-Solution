class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]][edges[i][1]]=edges[i][2];
            adj[edges[i][1]][edges[i][0]]=edges[i][2];
            adj[edges[i][0]][edges[i][0]]=0;
            adj[edges[i][1]][edges[i][1]]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j &&adj[i][j]<=distanceThreshold){
                    v[j]++;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<adj[i][j]<<"  ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" ";
        // }
        int mini=INT_MAX;
        int indx=-1;
        for(int i=0;i<n;i++){
            if(v[i]<=mini){
                mini=v[i];
                indx=i;
            }
        }
        return indx;





        
    }
};