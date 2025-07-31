class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>curr,prev;
        prev.insert(arr[0]);
        unordered_set<int>ans;
        for(int i=0;i<arr.size();i++){
            for(auto x:prev){
                curr.insert(x|arr[i]);
                ans.insert(x|arr[i]);
            }
            prev=curr;
            ans.insert(arr[i]);
            prev.insert(arr[i]);
            curr.clear();
        }
        return ans.size();
        
    }
};