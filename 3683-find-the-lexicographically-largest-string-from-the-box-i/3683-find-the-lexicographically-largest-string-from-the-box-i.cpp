class Solution {
public:
    string answerString(string word, int numFriends) {
        int maxsize = word.size()-numFriends+1;
        if(numFriends==1) return word;
        vector<string>ans;
        for(int i=0;i<word.size();i++){
            string s="";
            for(int j=i;j<i+maxsize;j++){
                if(j==word.size()) break;
                s+=word[j];
            }
            ans.push_back(s);
        }
        sort(ans.begin(),ans.end());
        return ans[ans.size()-1];

        
    }
};