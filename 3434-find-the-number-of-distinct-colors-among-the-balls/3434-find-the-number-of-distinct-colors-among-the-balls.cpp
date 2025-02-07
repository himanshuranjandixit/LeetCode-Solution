class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>mpp1;
        map<int,int>mpp2;
        vector<int>ans;
        for(auto it : queries){
           if(mpp1.find(it[0])!=mpp1.end()){
            mpp2[mpp1[it[0]]]--;
            if(mpp2[mpp1[it[0]]]==0) mpp2.erase(mpp1[it[0]]);
           }
           mpp1[it[0]]=it[1];
           mpp2[mpp1[it[0]]]++;
           ans.push_back(mpp2.size());

        }
        return ans;
    }
};