class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mpp;
        for(auto it : word){
            mpp[it]++;
        }
        int ans=INT_MAX;
        for(auto it:mpp){
            int temp=0;
            for(auto itt:mpp){
                if(itt.second<it.second) temp+=itt.second;
                else if(itt.second> it.second+k) temp+=itt.second-it.second -k;
            }
            ans=min(ans,temp);
        }
        return ans;
    }
};