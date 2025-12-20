class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int>t(energy.size());
        for(int i=energy.size()-1;i>=0;i--){
            if(i+k>=energy.size()) t[i]=energy[i];
            else{
                t[i]=t[i+k] + energy[i];
            }
        }
        return *max_element(t.begin(),t.end());

    }
};