class Solution {
public:
    bool check(const string& s, int i, int j ){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;

    }
    string longestPalindrome(string s) {
        for(int length=s.size();length>0;length--){
            for(int i=0;i<s.size()-length+1;i++){
                if(check(s,i,i+length-1)){
                    return s.substr(i,length);
                }
            }
        }
        return "";


    }
};