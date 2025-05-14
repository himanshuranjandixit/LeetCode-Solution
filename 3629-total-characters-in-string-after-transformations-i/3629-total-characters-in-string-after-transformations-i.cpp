class Solution {
public:
    int M = 1e9 +7;
    int lengthAfterTransformations(string s, int t) {
        vector<int>mpp(26,0);
        for(int i=0;i<s.size();i++){
        mpp[s[i]-'a']++;
        }
        while(t--){
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){
                if(i!=25){
                    temp[i+1]= (temp[i+1]+mpp[i])%M;
                }
                else{
                    temp[0]=(temp[0]+ mpp[25])%M;
                    temp[1]=(temp[1]+ mpp[25])%M;
                }
            }
            mpp=move(temp);
        }int ans=0;
        for(auto it : mpp){
            ans=(ans+it)%M;
        }
        return ans;
    }
};