class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());  
        if (s.find(endWord) == s.end()) return {};  // If endWord is not in wordList, return empty

        unordered_map<string, vector<string>> par;  // Stores parent words for each transformation
        unordered_set<string> level;  // Tracks words added in the current BFS level
        queue<string> q;
        q.push(beginWord);
        bool found = false;  // Flag to indicate if shortest paths are found

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> newLevel;  // Track words visited in this level
            while (sz--) {
                string word = q.front();
                q.pop();

                string org = word;  // Store original word
                for (int i = 0; i < word.size(); i++) {
                    char oldChar = word[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == oldChar) continue;
                        word[i] = ch;

                        if (s.find(word) != s.end()) {
                            if (par.find(word) == par.end()) {
                                q.push(word);
                                newLevel.insert(word);
                            }
                            par[word].push_back(org);  // Store parent for backtracking
                            if (word == endWord) found = true;  // Stop BFS once we reach endWord
                        }
                    }
                    word[i] = oldChar;  // Restore original character
                }
            }
            for (const string& w : newLevel) s.erase(w);  // Remove words visited in this level
        }

        vector<vector<string>> ans;
        if (found) {
            vector<string> vec;
            backtrack(ans, vec, endWord, beginWord, par);
        }
        return ans;
    }

private:
    void backtrack(vector<vector<string>>& ans, vector<string>& vec, string word, string& beginWord, 
                   unordered_map<string, vector<string>>& par) {
        vec.push_back(word);
        if (word == beginWord) {
            ans.push_back(vector<string>(vec.rbegin(), vec.rend()));  // Reverse path before adding
        } else {
            for (const string& parent : par[word]) {
                backtrack(ans, vec, parent, beginWord, par);
            }
        }
        vec.pop_back();
    }
};
