class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini =INT_MAX;
        set<int>st;
        for(auto it : nums){
            mini=min(it,mini);
            st.insert(it);
        }
        if(mini<k) return -1;
        if(mini==k) return st.size()-1;
        return st.size();
    }
};