class Solution {
public:
    int findCircleNum(vector<vector<int>>& isconnected) {
        vector<int>vis(isconnected.size(),0);
        int count=0;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                queue<int>q;
                q.push(i);
                count++;
                while(!q.empty()){
                    int val=q.front();
                    q.pop();
                    for(int it=0;it<isconnected[val].size();it++){
                        if(isconnected[val][it]==1 && vis[it]==0){
                            q.push(it);
                            vis[it]=1;
                        }
                    }

                }

            }
        }
        return count;
    }
};