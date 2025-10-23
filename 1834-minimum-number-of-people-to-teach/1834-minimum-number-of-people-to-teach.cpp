class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int ans=INT_MAX;
        unordered_set<int>mpp;
        for(auto &it :friendships){
            int check=false;
            for(int i=0;i<languages[it[0]-1].size();i++){
                for(int j=0;j<languages[it[1]-1].size();j++){
                    if(languages[it[0]-1][i]==languages[it[1]-1][j]){
                        check=true;
                        break;
                    }
                }
            }
            if(!check){
                mpp.insert(it[0]-1);
                mpp.insert(it[1]-1);
            }
        }
        for(int i=1;i<=n;i++){
            int cnt =0;
            int j=-1;
            for(auto &it :languages){
                j++;
                if(!mpp.count(j)) continue;
                for(auto &itt:it){
                    if(itt==i){
                        cnt++;
                        break;
                    }
                }

            }
            ans=min(ans,(int)mpp.size()-cnt);
        }
        return ans;
        
    }
};