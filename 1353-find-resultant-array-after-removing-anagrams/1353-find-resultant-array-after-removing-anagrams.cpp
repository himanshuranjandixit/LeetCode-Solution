class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        string prev ="";
        for(auto it : words){
            string sortedWord =it;
            sort(sortedWord.begin(),sortedWord.end());
            if (sortedWord != prev){
                ans.push_back(it);
                prev= sortedWord;
            }
        }
        return ans;
    }
};