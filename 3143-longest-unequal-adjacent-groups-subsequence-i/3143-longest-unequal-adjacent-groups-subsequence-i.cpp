class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>v0,v1;
        bool num0=true;
        bool num1=true;
        for(int i=0;i<words.size();i++){
            if(groups[i]==0 && num0){
                v0.push_back(words[i]);
                num0=false;
            }
            else if(groups[i]==1 && !num0){
                v0.push_back(words[i]);
                num0=true;
            }
            if(groups[i]==1 && num1){
                v1.push_back(words[i]);
                num1=false;
            }
            else if(groups[i]==0 && !num1){
                v1.push_back(words[i]);
                num1=true;
            }


        }
        if(v0.size()>v1.size()) return v0;
        return v1;
        
    }
};