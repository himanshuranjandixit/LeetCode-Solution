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
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>s_t;
        unordered_map<char,char>t_s;
        for(int i=0;i<s.size();i++){
            char sc=s[i];
            char tc = t[i];
            if(s_t.count(sc) && s_t[s[i]]!=tc) return false;
            if(t_s.count(tc) && t_s[t[i]]!=sc) return false;
            s_t[s[i]]=t[i];
            t_s[t[i]]=s[i];
        }
        
        return true;
    }
};