class Solution {
public:
    unordered_set<string>seen;
    string ans;
    int k, n;
    void dfs(string node) {
        for (int i = 0; i < k; ++i) {
            string next = node + to_string(i);
            if (!seen.count(next)) {
                seen.insert(next);
                dfs(next.substr(1));
                ans += to_string(i);
            }
        }
    }

    string crackSafe(int _n, int _k) {
        n = _n;
        k = _k;
        string start(n - 1, '0');
        dfs(start);
        ans += start;
        return ans;
    }
};
