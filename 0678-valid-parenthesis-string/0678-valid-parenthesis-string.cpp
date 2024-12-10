class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            if(s[i]==')'){
                min--;
                max--;
            }
            if(s[i]=='*'){
                min--;
                max++;
            }
            if(min<0)min=0;
            if(max<0) return false;
        }
        if(min==0) return true;
        return false;
    }
};