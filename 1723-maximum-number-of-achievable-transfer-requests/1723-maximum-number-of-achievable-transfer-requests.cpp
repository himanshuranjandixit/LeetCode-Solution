class Solution {
public:
    int ans =0;
    bool isvalid(vector<int> &v){
        for(auto it : v){
            if(it!=0) return false;
        }
        return true;
    }
    void solve(vector<vector<int>>& requests, vector<int>& v, int count, int indx){
        if(indx==requests.size()){
            if(isvalid(v)) ans=max(ans,count);
            return ;
        }
        int from = requests[indx][0];
        int to = requests[indx][1];
        v[from]-=1;
        v[to]+=1;
        solve(requests,v,count+1,indx+1);
        v[from]+=1;
        v[to]-=1;
        solve(requests,v,count,indx+1); 
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>v(n,0);
        solve(requests,v,0,0);
        return ans;

        
    }
};