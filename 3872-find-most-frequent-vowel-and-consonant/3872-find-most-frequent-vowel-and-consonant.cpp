class Solution {
public:
    int maxFreqSum(string s) {
        int maxi=0;
        int maxx=0;
        unordered_map<int,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        for(auto it:mpp){
            if(it.first=='a' || it.first=='e' || it.first=='i' || it.first=='o'||it.first=='u'){
                maxi=max(maxi,it.second);
            }
            else maxx=max(maxx,it.second);
        }
        return maxi+maxx;
        
    }
};