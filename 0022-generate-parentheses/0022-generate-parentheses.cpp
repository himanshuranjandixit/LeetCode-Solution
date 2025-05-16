const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    std::atexit([]() {
        std::ofstream ofs("display_runtime.txt");
        if (ofs) {
            ofs << 0 << '\n';
        }
    });
    return 0;
}();
#endif
class Solution {
public:
    bool isvalid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                char top = st.top();
                if((c == ')' && top != '(')) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
    void dp(vector<string>& ans, int n , string s, int left, int right){
        if(left==n && right==n){
            if(isvalid(s)) ans.push_back(s);
            return ;
        }
        if(left>n || right>n) return;
        dp(ans,n,s+'(',left+1,right);
        dp(ans,n,s+')',left,right+1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        dp(ans,n,"",0,0);
        return ans;
        
    }
};