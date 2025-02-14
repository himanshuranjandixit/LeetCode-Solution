class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int bal=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(bal>0) result+=s[i];
                bal++;
                
            }
            else{
                bal--;
                if(bal>0){
                    result+=s[i];
                }
            }
        }
        return result;
        
    }
};