class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(auto &it : brokenLetters){
            st.insert(it);
        }
        stringstream ss(text);
        vector<string>words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        int cnt=0;
        for(auto &it :words){
            for(auto &ch : it){
                if(st.count(ch)){
                    cnt++;
                    break;
                }
            }
        }
        return words.size()-cnt;

        
    }
};