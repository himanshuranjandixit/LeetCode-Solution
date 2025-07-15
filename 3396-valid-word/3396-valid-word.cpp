class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool checkvowel = false;
        bool checkconst = false;
        for(auto it:word){
            if(!isalnum(it)) return false;
            else{
                if(tolower(it)=='a' || tolower(it)=='e' || tolower(it)=='i' || tolower(it)=='o' || tolower(it)=='u') checkvowel = true;
                else if(!(it>='0'&& it<='9')) checkconst = true;

            }
        }
        return checkvowel & checkconst;
        
    }
};