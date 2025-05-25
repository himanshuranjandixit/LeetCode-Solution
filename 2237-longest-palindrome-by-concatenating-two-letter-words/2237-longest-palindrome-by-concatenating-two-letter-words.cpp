class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mpp;
        for(auto it :words){
            mpp[it]++;
        }
        int ans=0;
        int maxio=0;
        int maxie=0;
        for(auto it:mpp){
            string s=it.first;
            reverse(s.begin(),s.end());
            if(mpp.find(s)!=mpp.end() && s!=it.first){
                int val=min(it.second,mpp[s]);
                mpp[it.first]-=val;
                mpp[s]-=val;
                ans+=4*val;

            }
            else if(s==it.first){
                maxie+=it.second/2;
                if(it.second%2!=0) maxio=2;
               
            }
        }
        ans+=4*maxie+maxio;
        return ans;
        
    }
};