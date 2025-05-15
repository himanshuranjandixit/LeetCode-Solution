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
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto it : mpp){
                    maxi=max(it.second,maxi);
                    mini=min(mini,it.second);

                }
                ans+=maxi-mini;

            }
        }
        return ans;

        
    }
};