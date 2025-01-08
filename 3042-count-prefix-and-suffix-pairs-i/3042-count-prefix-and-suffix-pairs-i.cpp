class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans =0;
        for(int i=0;i<words.size();i++){
            string s = words[i];
            for(int j=i+1;j<words.size();j++){
                string p = words[j];
                int checksuffix=1;
                int checkprefix=1;
                int n =p.size();
                if(s.size()>n) continue;
                for(int i=0;i<s.size();i++){
                    if(s[i]!=p[i]){
                        checkprefix=0;
                        break;
                    }

                }
                if(checkprefix==0) continue;
                for(int i=0;i<s.size();i++){
                    if(s[i]!=p[n-s.size()+i]){
                        checksuffix=0;
                        break;
                    }

                }
                if(checksuffix==0) continue;
                ans++;

            }
        }
        return ans;
    }
};