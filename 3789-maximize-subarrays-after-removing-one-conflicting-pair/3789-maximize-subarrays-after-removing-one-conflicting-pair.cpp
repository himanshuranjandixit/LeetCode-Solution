class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long validSubarrays = 0;
        int maxLeft = 0, secondMaxLeft = 0;
        vector<long long> gains(n + 2, 0);
        vector<vector<int>> conflicts(n + 2);

        for (auto &p : conflictingPairs) {
            int a = p[0], b = p[1];
            conflicts[max(a, b)].push_back(min(a, b));
        }

        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }
            validSubarrays += right - maxLeft;
            gains[maxLeft] += (maxLeft - secondMaxLeft);
        }

        long long bestGain = 0;
        for (long long g : gains) {
            bestGain = max(bestGain, g);
        }

        return validSubarrays + bestGain;
    }
};