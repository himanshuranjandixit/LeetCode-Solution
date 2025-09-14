class Solution {
    set<string> direct_check;
    map<string, int> capitalization;
    map<string, int> vowelError;
    vector<string> ans;

public:
    void ToLower(string &s) {
        for(char &ch : s) {
            ch = tolower(ch);
        }
    }
    bool isVowel(char &ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
 
    void vowelPlaceholder(string &s) {
        for(char &ch : s) {
            if(isVowel(ch)) {
                ch = '#';
            }
        }
    }
 
    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries) {
        int n = wordList.size();
        int q = queries.size();

        for(int i = 0; i < n; i++) {
            string s = wordList[i];
            direct_check.insert(s);

            ToLower(s);

            if(capitalization.find(s) == capitalization.end())
                capitalization[s] = i;

            vowelPlaceholder(s);
            if(vowelError.find(s) == vowelError.end())
                vowelError[s] = i;
        }
        for(string &s : queries) {
            if(direct_check.find(s) != direct_check.end()) {
                ans.push_back(s);
                continue;
            }
            ToLower(s);
            if(capitalization.find(s) != capitalization.end()) {
                ans.push_back(wordList[capitalization[s]]);
                continue;
            }

            vowelPlaceholder(s);
            if(vowelError.find(s) != vowelError.end()) {
                ans.push_back(wordList[vowelError[s]]);
            }
            else ans.push_back("");
        }
        return ans;

    }
};