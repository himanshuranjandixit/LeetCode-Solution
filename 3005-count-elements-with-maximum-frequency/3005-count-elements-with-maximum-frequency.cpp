class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums) mpp[it]++;
        int maxi=0;
        int ans=0;
        for(auto &[_,freq] :mpp) maxi=max(freq,maxi);
        for(auto &[_,freq]:mpp){
            if(freq==maxi) ans+=maxi;
        }
        return ans;


        
    }
};