class Solution {
public:
    bool solve(vector<int>& arr, int indx,vector<int>& vis){
        if(arr[indx]==0) return true;
        vis[indx]=1;
        bool left = false;
        bool right = false;
        if(indx - arr[indx] >=0 && !vis[indx - arr[indx]]) left = solve(arr, indx - arr[indx],vis);
        if(indx + arr[indx] <arr.size() && ! vis[indx + arr[indx]] ) right = solve(arr, indx + arr[indx],vis);
        return left | right ;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return solve(arr,start,vis);

        
    }
};