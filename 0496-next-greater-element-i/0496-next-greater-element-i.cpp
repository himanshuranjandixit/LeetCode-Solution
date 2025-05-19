class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            int nge=-1;
            while(!st.empty()){
                if(nums2[i]<st.top()){
                    nge=st.top();
                    break;
                }
                st.pop();
            }
            st.push(nums2[i]);
            mpp[nums2[i]]=nge;
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};