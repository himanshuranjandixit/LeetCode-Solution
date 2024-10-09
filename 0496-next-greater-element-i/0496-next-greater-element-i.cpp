class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>v;
        // for(int i=0;i<nums1.size();i++){
        //     int val=-1;
        //     for(int j=0;j<nums2.size();j++){
        //         if(nums1[i]==nums2[j]){
        //             while(j!=nums2.size()){
        //                 if(nums1[i]<nums2[j]){
        //                     val=nums2[j];
        //                     break;
        //                 }
        //                 j++;
        //             }
        //             break;
        //         }

        //     }
        //     v.push_back(val);
        // }
        // return v;
        
        vector<int>ans;
        stack<int>st;
        map<int,int>mpp;
        st.push(-1);
        for(int i=nums2.size()-1;i>-1;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i]){
                mpp[nums2[i]]=st.top();
            }
            else mpp[nums2[i]]=-1;
            st.push(nums2[i]);
        }
        for(auto it:nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};