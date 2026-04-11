class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2) return true;
        string S1=s1;
        string S2=s2;
        char temp = S1[0];
        S1[0] = S1[2];
        S1[2]=temp;
        if(S1==S2) return true;
        temp = S1[1];
        S1[1] = S1[3];
        S1[3]= temp;
        if(S1==S2) return true;
        S1=s1;S2=s2;
        temp = S1[1];
        S1[1] = S1[3];
        S1[3]= temp;
        if(S1==S2) return true;
        return false;

        
    }
};