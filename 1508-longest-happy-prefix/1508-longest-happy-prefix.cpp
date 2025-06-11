class Solution {
public:
    void findlps(string& s, vector<int>&lps){
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<s.size()){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
    }
    string longestPrefix(string s) {
        vector<int>lps(s.size());
        findlps(s,lps);
        int indx=lps[s.size()-1];
        string ans="";
        for(int i=0;i<indx;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};