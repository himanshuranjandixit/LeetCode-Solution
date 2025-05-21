class Solution {
public:
    string minWindow(string s, string t) {
        int low=0;
        int high=0;
        int indx=-1;
        int mini=INT_MAX;
        int cnt=0;
        unordered_map<int,int>mpp;
        for(auto it :t){
            mpp[it]++;
        }
        while(high<s.size()){
            if(mpp[s[high]]>0) cnt++;
            mpp[s[high]]--;
            while(cnt==t.size()){
                if(high-low+1<mini){
                    mini=high-low+1;
                    indx=low;
                }
                mpp[s[low]]++; 
                if(mpp[s[low]]>0) cnt--;
                low++;
            }
            high++;
        }
        if(indx==-1) return "";
        return s.substr(indx,mini);
    }
};