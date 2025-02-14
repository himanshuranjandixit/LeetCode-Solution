class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>words;
        string ans;
        string word;
        while(ss >> word){
            words.push_back(word);
        }
        for(int i=words.size()-1;i>=0;i--){
            ans+=words[i];
            if(i!=0) ans+=" ";
        }
        return ans ;
        
    }
};