class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        for(int j=2;j<=n;j++){
            int cnt=1;
            string ss="";
            for(int i=0;i<s.size()-1;i++){
                if(s[i]==s[i+1]){
                    cnt++;
                }
                else{
                    ss+=to_string(cnt) + s[i];
                    cnt=1;
                }

            }
            ss+=to_string(cnt) + s[s.size()-1];
            s=ss;
        }
        return s;
       
        
    }
};