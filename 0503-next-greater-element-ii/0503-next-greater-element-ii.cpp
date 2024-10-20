class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // vector<int>ans;
        // vector<int>v(nums.size());
        // for(int i=0;i<nums.size();i++){
        //     v[i]=nums[i];
        // }
        // sort(v.begin(),v.end());
        // int indx=0;
        // for(int i=0;i<nums.size();i++){
        //     int check=1;
        //     int j=i+1;
        //     if(i==nums.size()-1) j=0;
        //     while(j!=i){
        //         if(j==nums.size()) j=0;
        //         if(i==nums.size()-1){
        //             if(nums[i]<v[0]){
        //                 ans.push_back(v[0]);
        //                 check=0;
        //                 break;
        //             }
        //         }
        //         if(i!=nums.size()-1 && nums[i]<v[j]){
        //             ans.push_back(v[j]);
        //             check=0;
        //             break;

        //         }
        //         j++;
        //     }
        //     if(check) ans.push_back(-1);
        // }
        // return ans;

        stack<int>st;
        stack<int>st1;
        st1.push(-1);
        vector<int>ans;
        reverse(nums.begin(),nums.end());
        int n =nums.size();
        for(int i=0;i<n;i++){
            st1.push(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(st.empty()){
                while(!st1.empty() && st1.top()<=nums[i]){
                    st1.pop();
                }
                if(st1.empty())ans.push_back(-1);
                else ans.push_back(st1.top());
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    while(!st1.empty() && st1.top()<=nums[i]){
                        st1.pop();
                    }
                    if(st1.empty()) ans.push_back(-1);
                    else ans.push_back(st1.top());
                }
                else{
                    ans.push_back(st.top());
                }
                st.push(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;




    }
};