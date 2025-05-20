class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()<=k) return "0";
        stack<char>st;
        st.push(num[0]);
        int i;
        for(i=1;i<num.size();i++){
            while(k!=0 && !st.empty() && num[i]<st.top()){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k!=0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        string ans1="";
        int indx=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0') indx++;
            else break;
        }
        for(int i=indx;i<ans.size();i++){
            ans1+=ans[i];
        }
        // reverse(ans1.begin(),ans1.end());
        if(ans1=="") return "0";
        return ans1;

        
    }
};