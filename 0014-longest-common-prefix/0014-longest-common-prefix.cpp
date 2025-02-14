class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int mini=strs[0].size();
        for(int i=0;i<strs.size();i++) mini=min(mini,(int)strs[i].size());
        for(int i=0;i<mini;i++){
            bool found=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=strs[j-1][i]){
                    found=false;
                    break;
                }

            }
            if(found==true) ans+=strs[0][i];
            else break;
        }
        return ans;
        
    }
};