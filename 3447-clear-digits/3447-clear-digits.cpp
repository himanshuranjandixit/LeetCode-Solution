class Solution {
public:
    string clearDigits(string s) {
        string ans;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]) && j>0){
                j--;
            }
            else s[j++]=s[i];
        }
        s.resize(j);
        return s;
    }
};