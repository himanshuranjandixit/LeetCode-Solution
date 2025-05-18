class Solution {
public:
    // void solve(string& s, vector<string>& wordDict, string& v,int idx,bool& ans){
    //     if(ans) return;
    //     if(s==v){
    //         ans= true;
    //         return;
    //     }
    //     if(v.size()>s.size()) return ;
    //     int j=0;
    //     // while(j<v.size()){
    //     //     if(v[j]!=s[j]){
    //     //         return;
    //     //     }
    //     //     j++;
    //     // }
    //     for(int i=0;i<wordDict.size();i++){
    //         if(wordDict[i]==s.substr(idx,wordDict[i].size())){
    //             string temp=v;
    //             v+=wordDict[i];
    //             solve(s,wordDict,v,idx+wordDict[i].size(),ans);
    //             v=temp;
    //         }
    //     }
    //     return;
    // }
    int n;
    unordered_set<string>st;
    int solve(string& s,  vector<int>& v, int indx){
        if(indx>=n) return v[indx]=1;
        if(st.find(s)!=st.end()) return v[indx]=1;
        if(v[indx]!=-1) return v[indx];
        for(int i=1;i<=n;i++){
            string temp =s.substr(indx,i);
            if(st.find(temp) !=st.end() && solve(s,v,indx+i))
            return v[indx] = 1;
        }
        return v[indx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // string v;
        // bool ans=false;
        // solve(s,wordDict,v,0,ans);
        // return ans;
        n= s.size();
        vector<int>v(301,-1);
        for(auto it : wordDict) st.insert(it);
        int ans= solve(s,v,0);
        if(ans) return true;
        return false;

        
    }
};