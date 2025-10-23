class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt =0;
        unordered_set<int>st;
        st.insert('a');st.insert('e');st.insert('i');st.insert('o');st.insert('u');
        for(auto &it:s){
            if(st.count(it)) cnt++;
        }
        return ((cnt==0) ? false : true);
        
    }
};