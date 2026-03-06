class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int ans=0;
        int maxel = *max_element(nums.begin(),nums.end());
        vector<int>v(maxel+1);
        for(auto it :nums){
            v[it]+=1;
        }
        for(int i=1;i<v.size();i++){
            v[i]+=v[i-1];
        }
        for(int it=0;it<=maxel;it++){
            int l = max(0,it-k);
            int r = min(maxel,it+k);
            int total = v[r]- (l>0 ? v[l-1] : 0);
            int numcount = v[it]-(it>0 ? v[it-1] : 0);
            int mini=min(numOperations,total-numcount);
            ans=max(ans,mini+numcount);
        }
        return ans;

        
    }
};