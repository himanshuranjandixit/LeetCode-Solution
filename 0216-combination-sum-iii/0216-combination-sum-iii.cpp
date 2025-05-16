class Solution {
public:
    void recursion(vector<vector<int>>& ans, vector<int>temp, vector<int>& v, int indx, int k , int n){
        if(n==0 && k==0){
            ans.push_back(temp);
            return;
        }
        if(n<0 ||k<0) return;
        for(int i=indx;i<9;i++){
            if(v[i]>n) break;
            temp.push_back(v[i]);
            recursion(ans,temp,v,i+1,k-1,n-v[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v({1,2,3,4,5,6,7,8,9});
        vector<int>temp;
        recursion(ans,temp,v,0,k,n);
        return ans;
        
    }
};