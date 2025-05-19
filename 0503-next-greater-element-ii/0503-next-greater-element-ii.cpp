class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--) st.push(nums[i]);
        for(int i=nums.size()-1;i>=0;i--){
            int nge=-1;
            while(!st.empty()){
                if(nums[i]<st.top()){
                    nge=st.top();
                    break;
                }
                st.pop();
            }
            st.push(nums[i]);
            ans[i]=nge;
        }
        return ans;
        
        
    }
};