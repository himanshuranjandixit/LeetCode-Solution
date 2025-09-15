class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int count = 0;
        vector<string>str;
        string temp ="";
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                if(!temp.empty()) str.push_back(temp);
                temp.clear();
            }
            else{
                temp +=text[i];
            }
        }
        if(!temp.empty()) str.push_back(temp);
        for(string &word:str){
            bool canType = true;
            for(auto &brk:brokenLetters){
                if(word.find(brk)!=string::npos){
                    canType = false;
                    break;
                }
            }
            if(canType) count++;
        }
        return count;
    }
};