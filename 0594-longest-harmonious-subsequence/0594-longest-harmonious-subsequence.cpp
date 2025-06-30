class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it :nums){
            mpp[it]++;
        }
        int len=0;
        for(auto it:mpp){
            if(mpp.count(it.first+1)){
                len=max(len,it.second + mpp[it.first+1]);
            }
        }
        return len;
    }
};