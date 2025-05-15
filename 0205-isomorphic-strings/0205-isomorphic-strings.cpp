class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s_t;
        unordered_map<char,char>t_s;
        for(int i=0;i<s.size();i++){
            char sc=s[i];
            char tc = t[i];
            if(s_t.count(sc) && s_t[s[i]]!=tc) return false;
            if(t_s.count(tc) && t_s[t[i]]!=sc) return false;
            s_t[s[i]]=t[i];
            t_s[t[i]]=s[i];
        }
        
        return true;
    }
};