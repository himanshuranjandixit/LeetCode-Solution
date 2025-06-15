class Solution {
public:
    int ans =INT_MAX;
    void backtracking(vector<int>& cookies, int indx, vector<int>& v){
        if(indx==cookies.size()){
            int val = *max_element(v.begin(),v.end());
            ans=min(ans,val);
            return;
        }
        for(int i=0;i<v.size();i++){
            v[i]+=cookies[indx];
            backtracking(cookies,indx+1,v);
            v[i]-=cookies[indx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>v(k,0);
        backtracking(cookies,0,v);
        return ans;

        
    }
};