class Solution {
public:
    bool checkpalindrome(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1]) return false;
        }
        return true;
    }
    void recursion(string& s,vector<vector<string>>& ans,vector<string> v, int indx){
        if(indx==s.size()){
            if(v.size()>=1) ans.push_back(v);
            return;
        }
        for(int i=indx;i<s.size();i++){
            string ss = s.substr(indx,i-indx+1);
            if(checkpalindrome(ss)){
                v.push_back(ss);
                recursion(s,ans,v,i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>v;
        recursion(s,ans,v,0);
        return ans;
        
    }
};