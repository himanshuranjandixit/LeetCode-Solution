class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int>mpp;
        for(auto it :nums){
            int val = it%value;
            if(val<0) val = value +val;
            mpp[val]++;
        }
        int i=0;
        for(auto &it:mpp){
            if(it.second>1) {
                mpp[it.first+value]+=it.second-1;
                it.second=1;
            }

        }
        for(auto it:mpp){
            if(it.first!=i) return i;
            i++;
        }
        return i;
        
    }
};