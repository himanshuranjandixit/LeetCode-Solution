class Solution {
public:
    int n;
    vector<int> score;
    vector<int> prereq;
    unordered_map<int, int> memo;

    int dfs(int mask, int pos) {
        if (mask == (1 << n) - 1)
            return 0;
        if (memo.count(mask))
            return memo[mask];
        int maxProfit = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) {
                if ((prereq[i] & mask) == prereq[i]) {
                    int curr = score[i] * pos + dfs(mask | (1 << i), pos + 1);
                    maxProfit = max(maxProfit, curr);
                }
            }
        }
        return memo[mask] = maxProfit;
    }

    int maxProfit(int _n, vector<vector<int>>& edges, vector<int>& _score) {
        if (edges.empty()) {
            sort(_score.begin(), _score.end());
            int ans = 0;
            for (int i = 0; i < _n; i++) {
                ans += _score[i] * (i + 1);
            }
            return ans;
        }
        n = _n;
        score = _score;
        prereq.assign(n, 0);
        memo.clear();
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            prereq[v] |= (1 << u);
        }

        return dfs(0, 1);
    }
};