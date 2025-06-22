class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int limit =0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(limit==k){
                ans.push_back(temp);
                limit=1;
                temp="";
                temp+=s[i];
            }
            else{
                temp+=s[i];
                limit++;
            }
        }
        if(limit!=0){
            while(limit!=k){
                temp+=fill;
                limit++;
            }
            ans.push_back(temp);
        }
        return ans;

        
    }
};