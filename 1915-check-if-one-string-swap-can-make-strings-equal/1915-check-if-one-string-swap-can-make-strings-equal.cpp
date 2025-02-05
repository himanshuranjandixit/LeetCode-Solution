class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count=0;
        string S1=s1;
        string S2=s2;
        sort(S1.begin(),S1.end());
        sort(S2.begin(),S2.end());
        if(S1!=S2) return false;
        for(int i=0;i<s2.size();i++ ){
            if(s1[i]!=s2[i]) count++;
        }
        if(count==0 || count==2) return true;
        return false;
     
        
    }
};