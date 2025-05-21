class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int maxfreq=0;
        unordered_map<int,int>mpp;
        while(r<s.size()){
            mpp[s[r]-'A']++;
            maxfreq=max(maxfreq,mpp[s[r]-'A']);
            if((r-l+1)-maxfreq>k){
                mpp[s[l]-'A']--;
                // maxfreq=0;
                // for(auto it:mpp) maxfreq=max(maxfreq,it.second);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};