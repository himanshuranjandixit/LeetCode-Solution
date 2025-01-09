class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>substring;
        for(int i=0;i<words.size();i++){
            string word=words[i];
            for(int j=0;j<words.size();j++){
                string wordI = words[j];
                if(i==j) continue;
                else if(wordI.find(word) < wordI.size()){
                    substring.push_back(word);
                    break;
                }
            }
        }
        return substring;
        
    }
};