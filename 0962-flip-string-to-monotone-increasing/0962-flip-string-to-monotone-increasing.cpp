class Solution {
public:
    int ans=INT_MAX;
    bool isvalid(string& s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i+1]<s[i]) return false;
        }
        return true;
    }
    void solve(string& s, int indx,int count){
        if(indx==s.size()){
            if(isvalid(s)) ans=min(ans,count);
            return ;
        }
        solve(s,indx+1,count);
        s[indx] = (s[indx] == '0') ? '1' : '0';
        solve(s, indx + 1, count + 1);
        s[indx] = (s[indx] == '0') ? '1' : '0';
        
    }
    int minFlipsMonoIncr(string s) {
        // solve(s,0,0);
        // return ans;
        int flip=0;
        int ones=0;
        for(auto it : s){
            if(it=='1') ones++;
            else flip =min(flip+1,ones);
        }
        return flip;
    }
};