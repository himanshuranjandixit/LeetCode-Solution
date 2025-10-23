class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string>lowerMap; 
        unordered_map<string,string>vowelMap; 

        auto maskVowels = [](const string &s){
            string t = s;
            for(char &c : t) if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'|| c=='A'||c=='E'||c=='I'||c=='O'||c=='U') c='*';
            return t;
        };
        for(auto &w : wordlist){
            string lw = w;
            transform(lw.begin(), lw.end(), lw.begin(),::tolower);
            if(!lowerMap.count(lw)) lowerMap[lw] = w;
            string masked = maskVowels(lw);
            if(!vowelMap.count(masked)) vowelMap[masked] = w;
        }

        vector<string> ans;
        for(auto &q : queries){
            if(exact.count(q)){
                ans.push_back(q); 
                continue;
            }
            string lq = q;
            transform(lq.begin(), lq.end(), lq.begin(),::tolower);
            if(lowerMap.count(lq)){
                ans.push_back(lowerMap[lq]); 
                continue;
            }
            string masked = maskVowels(lq);
            if(vowelMap.count(masked)) ans.push_back(vowelMap[masked]); 
            else ans.push_back(""); 
        }
        return ans;
    }
};
