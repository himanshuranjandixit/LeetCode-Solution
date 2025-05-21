class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.size()){
            while(st.find(s[r])!=st.end()){
                st.erase(s[l]);
                l++;
            }
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};