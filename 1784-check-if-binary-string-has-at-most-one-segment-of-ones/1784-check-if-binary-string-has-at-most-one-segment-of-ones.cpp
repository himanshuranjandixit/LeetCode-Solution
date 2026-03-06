class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ans =false;
        bool zeroes =false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                ans= true;
            }
            if(s[i]=='0'){
                if(ans==true) zeroes =true;
            }
            if(zeroes && s[i]=='1') return false;
        }
        return ans;
        
    }
};