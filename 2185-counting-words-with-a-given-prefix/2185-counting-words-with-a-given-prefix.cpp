class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int j=0;j<words.size();j++){
            string word =words[j];
            int IsPrefix=1;
            for(int k=0;k<pref.size();k++){
                if(k>word.size() || word[k]!=pref[k]){
                    IsPrefix=0;
                    break;
                }
            }
            count+=IsPrefix;
        }
        return count;
    }
};