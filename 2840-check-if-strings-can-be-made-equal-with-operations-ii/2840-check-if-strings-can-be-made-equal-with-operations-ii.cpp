class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>odd(26);
        vector<int>even(26);
        for(int i=0;i<s1.size();i++){
            if(i%2!=0) odd[s1[i]-'a']++;
            else even[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++){
            if(i%2!=0) odd[s2[i]-'a']--;
            else even[s2[i]-'a']--;
        }
        for(auto it:odd) if(it!=0) return false;
        for(auto it:even) if(it!=0) return false;
        return true;
    }
};