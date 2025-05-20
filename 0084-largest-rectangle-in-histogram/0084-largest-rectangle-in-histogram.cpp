class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        vector<int>prev(heights.size(),-1);
        for(int i=0;i<heights.size();i++){
            int pse=-1;
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()) pse=st.top();
            prev[i]=pse;
            st.push(i);
        }
        vector<int>next(heights.size(),-1);
        stack<int>st1;
        for(int i=heights.size()-1;i>=0;i--){
            int pse=heights.size();
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(!st1.empty()) pse=st1.top();
            next[i]=pse;
            st1.push(i);
        }
        int ans=0;
        for(int i=0;i<prev.size();i++){
            int length =next[i]- prev[i]-1;
            int val=0;
            val= (length)*heights[i];
            ans=max(ans,val);
        }
        return ans;
        
    }
};