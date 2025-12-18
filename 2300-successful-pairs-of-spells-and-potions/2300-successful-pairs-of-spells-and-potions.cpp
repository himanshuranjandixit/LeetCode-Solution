class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long val = success/spells[i] + (success%spells[i]!=0 ?1:0);
            auto it = lower_bound(potions.begin(),potions.end(),val);
            ans[i] = potions.size()-(it-potions.begin());
        }
        return ans;
        
    } 
}; 