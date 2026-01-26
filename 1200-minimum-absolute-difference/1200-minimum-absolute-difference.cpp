class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int mini = arr[1]-arr[0];
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]<mini){
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
                mini=arr[i+1]-arr[i];
            }
            else if(arr[i+1]-arr[i]==mini) ans.push_back({arr[i],arr[i+1]});
        }
        return ans;
        
    }
};