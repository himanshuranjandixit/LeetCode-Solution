class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>prefix(pref.size());
        prefix[0]=pref[0];
        for(int i=1;i<pref.size();i++){
            prefix[i]=pref[i]^ pref[i-1];
        }
        return prefix;
        
    }
};