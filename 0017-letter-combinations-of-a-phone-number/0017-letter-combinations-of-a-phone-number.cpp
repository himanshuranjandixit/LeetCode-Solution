class Solution {
public:
    void solve(string& digits, vector<string>& v, string temp,int idx, vector<string>& ans){
        if(idx>=digits.size()){
            ans.push_back(temp);
            return;
        }
        string s = v[(digits[idx]-'0')-2];
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            solve(digits,v,temp,idx+1,ans);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>v{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.size()==0) return ans;
        solve(digits,v,"",0,ans);
        return ans;

        
    }
};