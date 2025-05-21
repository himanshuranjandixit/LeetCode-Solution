class Solution {
public:
    int numberOfSubstrings(string s) {
        int low=0;
        int high=0;
        int ans=0;
        unordered_map<int,int>mpp;
        while(high<s.size()){
            mpp[s[high]]++;
            while(mpp.size()==3){
                ans+=s.size()-high;
                mpp[s[low]]--;
                if(mpp[s[low]]==0) mpp.erase(s[low]);
                low++;
            }
            high++;

        }
        return ans;
    }
};