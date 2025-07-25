class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int maxi=INT_MIN;
        for(auto it:nums){
            mpp[it]++;
            maxi = max(maxi,it);
        }
        if(maxi<0) return maxi;
        int ans=0;
        int temp;
        for(auto it:mpp){
            if(it.first>0) ans+=it.first;
        }
        return ans;

    }
};