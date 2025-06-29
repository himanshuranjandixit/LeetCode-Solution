class Solution {
public:

    vector<vector<int>>ans;
    void solve(int n , int k ,vector<int>& v,int indx){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        if(v.size()>k) return;
        if(indx==n+1) return;
        for(int i=indx;i<=n;i++){
            v.push_back(i);
            solve(n,k,v,i+1);
            v.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        solve(n,k,v,1);
        return ans;
        
    }
};