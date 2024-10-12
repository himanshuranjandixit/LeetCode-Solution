class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int>v = times[targetFriend];
        sort(times.begin(), times.end());
        int n = times.size();
        vector<int>v2(n);
        for (auto it : times) {
            for (int i = 0; i < n; i++) {
                if (v2[i] <= it[0]) {
                    v2[i] = it[1];
                    if (it == v) return i;
                    break;
                }
            }
        }
        return 0;
    }
};