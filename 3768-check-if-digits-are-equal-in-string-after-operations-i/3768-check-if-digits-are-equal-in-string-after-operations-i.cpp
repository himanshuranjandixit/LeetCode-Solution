class Solution {
public:
    bool hasSameDigits(string s) {
        if(s.size()==2){
            if(s[0]==s[1]) return true;
            else return false;
        }
        if(s.size()==1) return false;
        string ss="";
        for(int i=0;i<s.size()-1;i++){
            int temp1 = (s[i] - '0' + s[i+1] -'0')%10;
            ss+=to_string(temp1);
        }
        return hasSameDigits(ss);
        
    }
};